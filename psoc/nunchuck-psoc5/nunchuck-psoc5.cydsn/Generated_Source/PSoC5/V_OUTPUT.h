/*******************************************************************************
* File Name: V_OUTPUT.h  
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

#if !defined(CY_PINS_V_OUTPUT_H) /* Pins V_OUTPUT_H */
#define CY_PINS_V_OUTPUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "V_OUTPUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 V_OUTPUT__PORT == 15 && ((V_OUTPUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    V_OUTPUT_Write(uint8 value) ;
void    V_OUTPUT_SetDriveMode(uint8 mode) ;
uint8   V_OUTPUT_ReadDataReg(void) ;
uint8   V_OUTPUT_Read(void) ;
uint8   V_OUTPUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define V_OUTPUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define V_OUTPUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define V_OUTPUT_DM_RES_UP          PIN_DM_RES_UP
#define V_OUTPUT_DM_RES_DWN         PIN_DM_RES_DWN
#define V_OUTPUT_DM_OD_LO           PIN_DM_OD_LO
#define V_OUTPUT_DM_OD_HI           PIN_DM_OD_HI
#define V_OUTPUT_DM_STRONG          PIN_DM_STRONG
#define V_OUTPUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define V_OUTPUT_MASK               V_OUTPUT__MASK
#define V_OUTPUT_SHIFT              V_OUTPUT__SHIFT
#define V_OUTPUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define V_OUTPUT_PS                     (* (reg8 *) V_OUTPUT__PS)
/* Data Register */
#define V_OUTPUT_DR                     (* (reg8 *) V_OUTPUT__DR)
/* Port Number */
#define V_OUTPUT_PRT_NUM                (* (reg8 *) V_OUTPUT__PRT) 
/* Connect to Analog Globals */                                                  
#define V_OUTPUT_AG                     (* (reg8 *) V_OUTPUT__AG)                       
/* Analog MUX bux enable */
#define V_OUTPUT_AMUX                   (* (reg8 *) V_OUTPUT__AMUX) 
/* Bidirectional Enable */                                                        
#define V_OUTPUT_BIE                    (* (reg8 *) V_OUTPUT__BIE)
/* Bit-mask for Aliased Register Access */
#define V_OUTPUT_BIT_MASK               (* (reg8 *) V_OUTPUT__BIT_MASK)
/* Bypass Enable */
#define V_OUTPUT_BYP                    (* (reg8 *) V_OUTPUT__BYP)
/* Port wide control signals */                                                   
#define V_OUTPUT_CTL                    (* (reg8 *) V_OUTPUT__CTL)
/* Drive Modes */
#define V_OUTPUT_DM0                    (* (reg8 *) V_OUTPUT__DM0) 
#define V_OUTPUT_DM1                    (* (reg8 *) V_OUTPUT__DM1)
#define V_OUTPUT_DM2                    (* (reg8 *) V_OUTPUT__DM2) 
/* Input Buffer Disable Override */
#define V_OUTPUT_INP_DIS                (* (reg8 *) V_OUTPUT__INP_DIS)
/* LCD Common or Segment Drive */
#define V_OUTPUT_LCD_COM_SEG            (* (reg8 *) V_OUTPUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define V_OUTPUT_LCD_EN                 (* (reg8 *) V_OUTPUT__LCD_EN)
/* Slew Rate Control */
#define V_OUTPUT_SLW                    (* (reg8 *) V_OUTPUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define V_OUTPUT_PRTDSI__CAPS_SEL       (* (reg8 *) V_OUTPUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define V_OUTPUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) V_OUTPUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define V_OUTPUT_PRTDSI__OE_SEL0        (* (reg8 *) V_OUTPUT__PRTDSI__OE_SEL0) 
#define V_OUTPUT_PRTDSI__OE_SEL1        (* (reg8 *) V_OUTPUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define V_OUTPUT_PRTDSI__OUT_SEL0       (* (reg8 *) V_OUTPUT__PRTDSI__OUT_SEL0) 
#define V_OUTPUT_PRTDSI__OUT_SEL1       (* (reg8 *) V_OUTPUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define V_OUTPUT_PRTDSI__SYNC_OUT       (* (reg8 *) V_OUTPUT__PRTDSI__SYNC_OUT) 


#if defined(V_OUTPUT__INTSTAT)  /* Interrupt Registers */

    #define V_OUTPUT_INTSTAT                (* (reg8 *) V_OUTPUT__INTSTAT)
    #define V_OUTPUT_SNAP                   (* (reg8 *) V_OUTPUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_V_OUTPUT_H */


/* [] END OF FILE */
