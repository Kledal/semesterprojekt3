/*******************************************************************************
* File Name: SPIS_1_mosi_s.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SPIS_1_mosi_s_H) /* Pins SPIS_1_mosi_s_H */
#define CY_PINS_SPIS_1_mosi_s_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SPIS_1_mosi_s_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SPIS_1_mosi_s_Write(uint8 value) ;
void    SPIS_1_mosi_s_SetDriveMode(uint8 mode) ;
uint8   SPIS_1_mosi_s_ReadDataReg(void) ;
uint8   SPIS_1_mosi_s_Read(void) ;
uint8   SPIS_1_mosi_s_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SPIS_1_mosi_s_DRIVE_MODE_BITS        (3)
#define SPIS_1_mosi_s_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SPIS_1_mosi_s_DRIVE_MODE_BITS))
#define SPIS_1_mosi_s_DRIVE_MODE_SHIFT       (0x00u)
#define SPIS_1_mosi_s_DRIVE_MODE_MASK        (0x07u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)

#define SPIS_1_mosi_s_DM_ALG_HIZ         (0x00u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_DIG_HIZ         (0x01u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_RES_UP          (0x02u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_RES_DWN         (0x03u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_OD_LO           (0x04u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_OD_HI           (0x05u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_STRONG          (0x06u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)
#define SPIS_1_mosi_s_DM_RES_UPDWN       (0x07u << SPIS_1_mosi_s_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SPIS_1_mosi_s_MASK               SPIS_1_mosi_s__MASK
#define SPIS_1_mosi_s_SHIFT              SPIS_1_mosi_s__SHIFT
#define SPIS_1_mosi_s_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SPIS_1_mosi_s_PS                     (* (reg32 *) SPIS_1_mosi_s__PS)
/* Port Configuration */
#define SPIS_1_mosi_s_PC                     (* (reg32 *) SPIS_1_mosi_s__PC)
/* Data Register */
#define SPIS_1_mosi_s_DR                     (* (reg32 *) SPIS_1_mosi_s__DR)
/* Input Buffer Disable Override */
#define SPIS_1_mosi_s_INP_DIS                (* (reg32 *) SPIS_1_mosi_s__PC2)


#if defined(SPIS_1_mosi_s__INTSTAT)  /* Interrupt Registers */

    #define SPIS_1_mosi_s_INTSTAT                (* (reg32 *) SPIS_1_mosi_s__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SPIS_1_mosi_s_H */


/* [] END OF FILE */
