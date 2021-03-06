/*******************************************************************************
File Name: CYBLE_custom.c
Version 1.20

Description:
 Contains the source code for the Custom Service.

********************************************************************************
Copyright 2014-2015, Cypress Semiconductor Corporation.  All rights reserved.
You may use this file only in accordance with the license, terms, conditions,
disclaimers, and limitations in the end user license agreement accompanying
the software package with which this file was provided.
*******************************************************************************/


#include "BLE_1_eventHandler.h"

#if(0u != CYBLE_CUSTOMS_SERVICE_COUNT)

/* If any custom service with custom characterisctis is defined in the
* customizer's GUI their handles will be present in this array.
*/
/* This array contains attribute handles for the defined Custom Services and their characteristics and descriptors.
   The array index definitions are located in the CYBLE_custom.h file. */
const CYBLE_CUSTOMS_T cyBle_customs[0x02u] = {

    /* CapSense Service service */
    {
        0x000Cu, /* Handle of the CapSense Service service */ 
        {

            /* CapSense Proximity Characteristic characteristic */
            {
                0x000Eu, /* Handle of the CapSense Proximity Characteristic characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    0x000Fu, /* Handle of the Client Characteristic Configuration descriptor */ 
                    CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* CapSense Slider Characteristic characteristic */
            {
                0x0011u, /* Handle of the CapSense Slider Characteristic characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    0x0012u, /* Handle of the Characteristic User Description descriptor */ 
                    0x0013u, /* Handle of the Client Characteristic Configuration descriptor */ 
                }, 
            },
        }, 
    },

    /* RGB LED Charateristic service */
    {
        0x0014u, /* Handle of the RGB LED Charateristic service */ 
        {

            /* RGB LED Characteristic characteristic */
            {
                0x0016u, /* Handle of the RGB LED Characteristic characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    0x0017u, /* Handle of the Characteristic User Description descriptor */ 
                    CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                    CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
        }, 
    },
};


#endif /* (0u != CYBLE_CUSTOMS_SERVICE_COUNT) */

#if(0u != CYBLE_CUSTOMC_SERVICE_COUNT)

#endif /* (0u != CYBLE_CUSTOMC_SERVICE_COUNT) */


/* [] END OF FILE */
