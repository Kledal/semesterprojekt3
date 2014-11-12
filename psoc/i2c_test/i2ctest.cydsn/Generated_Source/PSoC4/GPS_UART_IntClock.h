/*******************************************************************************
* File Name: GPS_UART_IntClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_GPS_UART_IntClock_H)
#define CY_CLOCK_GPS_UART_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void GPS_UART_IntClock_StartEx(uint32 alignClkDiv);
#define GPS_UART_IntClock_Start() \
    GPS_UART_IntClock_StartEx(GPS_UART_IntClock__PA_DIV_ID)

#else

void GPS_UART_IntClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void GPS_UART_IntClock_Stop(void);

void GPS_UART_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 GPS_UART_IntClock_GetDividerRegister(void);
uint8  GPS_UART_IntClock_GetFractionalDividerRegister(void);

#define GPS_UART_IntClock_Enable()                         GPS_UART_IntClock_Start()
#define GPS_UART_IntClock_Disable()                        GPS_UART_IntClock_Stop()
#define GPS_UART_IntClock_SetDividerRegister(clkDivider, reset)  \
    GPS_UART_IntClock_SetFractionalDividerRegister((clkDivider), 0u)
#define GPS_UART_IntClock_SetDivider(clkDivider)           GPS_UART_IntClock_SetDividerRegister((clkDivider), 1u)
#define GPS_UART_IntClock_SetDividerValue(clkDivider)      GPS_UART_IntClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define GPS_UART_IntClock_DIV_ID     GPS_UART_IntClock__DIV_ID

#define GPS_UART_IntClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define GPS_UART_IntClock_CTRL_REG   (*(reg32 *)GPS_UART_IntClock__CTRL_REGISTER)
#define GPS_UART_IntClock_DIV_REG    (*(reg32 *)GPS_UART_IntClock__DIV_REGISTER)

#define GPS_UART_IntClock_CMD_DIV_SHIFT          (0u)
#define GPS_UART_IntClock_CMD_PA_DIV_SHIFT       (8u)
#define GPS_UART_IntClock_CMD_DISABLE_SHIFT      (30u)
#define GPS_UART_IntClock_CMD_ENABLE_SHIFT       (31u)

#define GPS_UART_IntClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << GPS_UART_IntClock_CMD_DISABLE_SHIFT))
#define GPS_UART_IntClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << GPS_UART_IntClock_CMD_ENABLE_SHIFT))

#define GPS_UART_IntClock_DIV_FRAC_MASK  (0x000000F8u)
#define GPS_UART_IntClock_DIV_FRAC_SHIFT (3u)
#define GPS_UART_IntClock_DIV_INT_MASK   (0xFFFFFF00u)
#define GPS_UART_IntClock_DIV_INT_SHIFT  (8u)

#else 

#define GPS_UART_IntClock_DIV_REG        (*(reg32 *)GPS_UART_IntClock__REGISTER)
#define GPS_UART_IntClock_ENABLE_REG     GPS_UART_IntClock_DIV_REG
#define GPS_UART_IntClock_DIV_FRAC_MASK  GPS_UART_IntClock__FRAC_MASK
#define GPS_UART_IntClock_DIV_FRAC_SHIFT (16u)
#define GPS_UART_IntClock_DIV_INT_MASK   GPS_UART_IntClock__DIVIDER_MASK
#define GPS_UART_IntClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_GPS_UART_IntClock_H) */

/* [] END OF FILE */
