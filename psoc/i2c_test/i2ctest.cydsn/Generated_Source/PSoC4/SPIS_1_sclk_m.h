/*******************************************************************************
* File Name: SPIS_1_sclk_m.h  
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

#if !defined(CY_PINS_SPIS_1_sclk_m_H) /* Pins SPIS_1_sclk_m_H */
#define CY_PINS_SPIS_1_sclk_m_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SPIS_1_sclk_m_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SPIS_1_sclk_m_Write(uint8 value) ;
void    SPIS_1_sclk_m_SetDriveMode(uint8 mode) ;
uint8   SPIS_1_sclk_m_ReadDataReg(void) ;
uint8   SPIS_1_sclk_m_Read(void) ;
uint8   SPIS_1_sclk_m_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SPIS_1_sclk_m_DRIVE_MODE_BITS        (3)
#define SPIS_1_sclk_m_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SPIS_1_sclk_m_DRIVE_MODE_BITS))
#define SPIS_1_sclk_m_DRIVE_MODE_SHIFT       (0x00u)
#define SPIS_1_sclk_m_DRIVE_MODE_MASK        (0x07u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)

#define SPIS_1_sclk_m_DM_ALG_HIZ         (0x00u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_DIG_HIZ         (0x01u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_RES_UP          (0x02u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_RES_DWN         (0x03u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_OD_LO           (0x04u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_OD_HI           (0x05u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_STRONG          (0x06u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)
#define SPIS_1_sclk_m_DM_RES_UPDWN       (0x07u << SPIS_1_sclk_m_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SPIS_1_sclk_m_MASK               SPIS_1_sclk_m__MASK
#define SPIS_1_sclk_m_SHIFT              SPIS_1_sclk_m__SHIFT
#define SPIS_1_sclk_m_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SPIS_1_sclk_m_PS                     (* (reg32 *) SPIS_1_sclk_m__PS)
/* Port Configuration */
#define SPIS_1_sclk_m_PC                     (* (reg32 *) SPIS_1_sclk_m__PC)
/* Data Register */
#define SPIS_1_sclk_m_DR                     (* (reg32 *) SPIS_1_sclk_m__DR)
/* Input Buffer Disable Override */
#define SPIS_1_sclk_m_INP_DIS                (* (reg32 *) SPIS_1_sclk_m__PC2)


#if defined(SPIS_1_sclk_m__INTSTAT)  /* Interrupt Registers */

    #define SPIS_1_sclk_m_INTSTAT                (* (reg32 *) SPIS_1_sclk_m__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SPIS_1_sclk_m_H */


/* [] END OF FILE */
