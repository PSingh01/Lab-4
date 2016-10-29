/*****************************************************************************
* Included headers
*****************************************************************************/
#include <main.h>
#include <BLEApplications.h>
#include <stdbool.h>
#include <stdlib.h>

/*****************************************************************************
* Function Prototypes
*****************************************************************************/
static void InitializeSystem(void);
//static void HandleCapSenseSlider(void);
static void HandleCapSenseProximity(void);


int main()
{
    uint8 interruptStatus;
    CYBLE_LP_MODE_T bleMode;
    
    
    /* This function will initialize the system resources such as BLE and CapSense */
    InitializeSystem();
     
    for(;;)
    {
        /*Process event callback to handle BLE events. The events generated and 
		* used for this application are inside the 'CustomEventHandler' routine*/
              
        if(TRUE == deviceConnected)
		{
			UpdateNotificationCCCD();
            HandleCapSenseProximity();       
            /* Send CapSense Slider data when respective notification is enabled */
//			if(TRUE == sendCapSenseSliderNotifications)
//			{
//				HandleCapSenseSlider(); 
//			}       
        }
         
            bleMode = CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
            
            interruptStatus = CyEnterCriticalSection();
        
            if(CYBLE_BLESS_DEEPSLEEP == bleMode)
            {
                if((CyBle_GetBleSsState() == CYBLE_BLESS_STATE_ECO_ON) ||
                   (CyBle_GetBleSsState() == CYBLE_BLESS_STATE_DEEPSLEEP))
                {
                        //CySysPmDeepSleep();
                }
           }else{
                if(CyBle_GetBleSsState() != CYBLE_BLESS_STATE_EVENT_CLOSE)
                {
                    CySysPmSleep();
                }
            }
            CyExitCriticalSection(interruptStatus);
             CyBle_ProcessEvents();
        }
        if(enterHibernateFlag)
        {
            /* Stop the BLE component */
            CyBle_Stop();
            
            /* Enable the Hibernate wakeup functionality */
            Switch_2_ClearInterrupt();
            ISR_Start();
             
            /* Enter hibernate mode */
            CySysPmHibernate(); 
          
        }
        	
}


/*******************************************************************************
* Function Name: InitializeSystem
********************************************************************************
* Summary:
* Start the components and initialize system.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void InitializeSystem(void)
{
	/* Enable global interrupt mask */
	CyGlobalIntEnable; 
		
	/* Start BLE component and register the CustomEventHandler function. This 
	 * function exposes the events from BLE component for application use */
    CyBle_Start(CustomEventHandler);
    CyBle_ProcessEvents();
    
	/* Start both the PrISM components for LED control*/
    PRS_1_Start();
    PRS_2_Start();
	
	/* The RGB LED on BLE Pioneer kit are active low. Drive HIGH on 
	 * pin for OFF and drive LOW on pin for ON*/
	PRS_1_WritePulse0(RGB_LED_OFF);
	PRS_1_WritePulse1(RGB_LED_OFF);
	PRS_2_WritePulse0(RGB_LED_OFF);
	
	/* Set Drive mode of output pins from HiZ to Strong */
	RED_SetDriveMode(RED_DM_STRONG);
	GREEN_SetDriveMode(GREEN_DM_STRONG);
	BLUE_SetDriveMode(BLUE_DM_STRONG);
	
	/* Initialize CapSense component and initialize baselines*/
	CapSense_Start();
	CapSense_InitializeAllBaselines();

}

//-----------------------------Exercise 1 Main Function---------------------------------------//
void HandleCapSenseProximity(void){
    
	uint8 prox;
    CapSense_EnableWidget(CapSense_PROXIMITYSENSOR0__PROX); 
    CapSense_UpdateEnabledBaselines();	
    CapSense_ScanWidget(CapSense_PROXIMITYSENSOR0__PROX);	
  
    while(CapSense_IsBusy());
    prox = CapSense_GetDiffCountData(CapSense_PROXIMITYSENSOR0__PROX);
    
    SendCapSenseNotification((uint8)prox);
    
    if (deviceConnected == FALSE){
        return;
    }
}	
//----------------------------------------------------------------------------------------//



/*******************************************************************************
* Function Name: HandleCapSenseSlider
********************************************************************************
* Summary:
* This function scans for finger position on CapSense slider, and if the  
* position is different, triggers separate routine for BLE notification.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
//void HandleCapSenseSlider(void)
//{
//	/* Last read CapSense slider position value */
//	static uint16 lastPosition;	
//	
//	/* Present slider position read by CapSense */
//	uint16 sliderPosition;
//		
//	/* Update CapSense baseline for next reading*/
//	CapSense_UpdateEnabledBaselines();	
//		
//	/* Scan the slider widget */
//	CapSense_ScanEnabledWidgets();			
//    
//	/* Wait for CapSense scanning to be complete. This could take about 5 ms */
//	while(CapSense_IsBusy());
//
//	/* Read the finger position on the slider */
//	sliderPosition = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);
    
    /*If finger is detected on the slider*/
//	if((sliderPosition != NO_FINGER) && (sliderPosition <= SLIDER_MAX_VALUE))
//	{
        /* If finger position on the slider is changed then send data as BLE 
         * notifications */
//        if(sliderPosition != lastPosition)
//		{
			/* Update global variable with present finger position on slider*/
//			lastPosition = sliderPosition;

//			SendCapSenseNotification((uint8)sliderPosition);

//		}	
//	}	
//}

/* [] END OF FILE */
