/*******************************************************************************
* File Name: UART_PC_tx.h  
* Version 2.0
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

#if !defined(CY_PINS_UART_PC_tx_H) /* Pins UART_PC_tx_H */
#define CY_PINS_UART_PC_tx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "UART_PC_tx_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    UART_PC_tx_Write(uint8 value) ;
void    UART_PC_tx_SetDriveMode(uint8 mode) ;
uint8   UART_PC_tx_ReadDataReg(void) ;
uint8   UART_PC_tx_Read(void) ;
uint8   UART_PC_tx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UART_PC_tx_DRIVE_MODE_BITS        (3)
#define UART_PC_tx_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - UART_PC_tx_DRIVE_MODE_BITS))
#define UART_PC_tx_DRIVE_MODE_SHIFT       (0x00u)
#define UART_PC_tx_DRIVE_MODE_MASK        (0x07u << UART_PC_tx_DRIVE_MODE_SHIFT)

#define UART_PC_tx_DM_ALG_HIZ         (0x00u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_DIG_HIZ         (0x01u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_RES_UP          (0x02u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_RES_DWN         (0x03u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_OD_LO           (0x04u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_OD_HI           (0x05u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_STRONG          (0x06u << UART_PC_tx_DRIVE_MODE_SHIFT)
#define UART_PC_tx_DM_RES_UPDWN       (0x07u << UART_PC_tx_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define UART_PC_tx_MASK               UART_PC_tx__MASK
#define UART_PC_tx_SHIFT              UART_PC_tx__SHIFT
#define UART_PC_tx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UART_PC_tx_PS                     (* (reg32 *) UART_PC_tx__PS)
/* Port Configuration */
#define UART_PC_tx_PC                     (* (reg32 *) UART_PC_tx__PC)
/* Data Register */
#define UART_PC_tx_DR                     (* (reg32 *) UART_PC_tx__DR)
/* Input Buffer Disable Override */
#define UART_PC_tx_INP_DIS                (* (reg32 *) UART_PC_tx__PC2)


#if defined(UART_PC_tx__INTSTAT)  /* Interrupt Registers */

    #define UART_PC_tx_INTSTAT                (* (reg32 *) UART_PC_tx__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins UART_PC_tx_H */


/* [] END OF FILE */
