/*******************************************************************************
* File Name: Button_Output.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Button_Output_H) /* Pins Button_Output_H */
#define CY_PINS_Button_Output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button_Output_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Button_Output_Write(uint8 value) ;
void    Button_Output_SetDriveMode(uint8 mode) ;
uint8   Button_Output_ReadDataReg(void) ;
uint8   Button_Output_Read(void) ;
uint8   Button_Output_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button_Output_DRIVE_MODE_BITS        (3)
#define Button_Output_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button_Output_DRIVE_MODE_BITS))

#define Button_Output_DM_ALG_HIZ         (0x00u)
#define Button_Output_DM_DIG_HIZ         (0x01u)
#define Button_Output_DM_RES_UP          (0x02u)
#define Button_Output_DM_RES_DWN         (0x03u)
#define Button_Output_DM_OD_LO           (0x04u)
#define Button_Output_DM_OD_HI           (0x05u)
#define Button_Output_DM_STRONG          (0x06u)
#define Button_Output_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Button_Output_MASK               Button_Output__MASK
#define Button_Output_SHIFT              Button_Output__SHIFT
#define Button_Output_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button_Output_PS                     (* (reg32 *) Button_Output__PS)
/* Port Configuration */
#define Button_Output_PC                     (* (reg32 *) Button_Output__PC)
/* Data Register */
#define Button_Output_DR                     (* (reg32 *) Button_Output__DR)
/* Input Buffer Disable Override */
#define Button_Output_INP_DIS                (* (reg32 *) Button_Output__PC2)


#if defined(Button_Output__INTSTAT)  /* Interrupt Registers */

    #define Button_Output_INTSTAT                (* (reg32 *) Button_Output__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Button_Output_DRIVE_MODE_SHIFT       (0x00u)
#define Button_Output_DRIVE_MODE_MASK        (0x07u << Button_Output_DRIVE_MODE_SHIFT)


#endif /* End Pins Button_Output_H */


/* [] END OF FILE */
