/** @defgroup dmamux_defines DMAMUX Defines
 *
 * @ingroup STM32WLxx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32WLxx DMAMUX DMA request router</b>
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
/**@{*/

#include <libopencm3/stm32/common/dmamux_common_all.h>

 /** @defgroup dmamux_reg_base DMAMUX register base addresses
  * @{
  */
#define DMAMUX1				DMAMUX_BASE
/**@}*/

/* --- DMAMUX_CxCR values ------------------------------------ */

/** @defgroup dmamux_cxcr_sync_id SYNCID Synchronization input selected
@{*/
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE0       0
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE1       1
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE2       2
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE3       3
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE4       4
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE5       5
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE6       6
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE7       7
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE8       8
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE9       9
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE10      10
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE11      11
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE12      12
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE13      13
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE14      14
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE15      15
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT0      16
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT1      17
#define DMAMUX_CxCR_SYNC_ID_LPTIM1_OUT       18
#define DMAMUX_CxCR_SYNC_ID_LPTIM2_OUT       19
#define DMAMUX_CxCR_SYNC_ID_LPTIM3_OUT       20
/**@}*/

/** @defgroup dmamux_cxcr_dmareq_id DMAREQID DMA request line selected
@{*/
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN0  1
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN1  2
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN2  3
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN3  4
#define DMAMUX_CxCR_DMAREQ_ID_ADC              5
#define DMAMUX_CxCR_DMAREQ_ID_DAC_OUT1         6
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_RX          7
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_TX          8
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_RX          9
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_TX          10
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_RX          11
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_TX          12
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_RX          13
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_TX          14
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_RX          15
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_TX          16
#define DMAMUX_CxCR_DMAREQ_ID_USART1_RX        17
#define DMAMUX_CxCR_DMAREQ_ID_USART1_TX        18
#define DMAMUX_CxCR_DMAREQ_ID_USART2_RX        19
#define DMAMUX_CxCR_DMAREQ_ID_USART2_TX        20
#define DMAMUX_CxCR_DMAREQ_ID_LPUART1_RX       21
#define DMAMUX_CxCR_DMAREQ_ID_LPUART1_TX       22
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH1         23
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH2         24
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH3         25
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH4         26
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_UP          27
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_TRIG        28
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_COM         29
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH1         30
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH2         31
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH3         32
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH4         33
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_UP          34
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_CH1        35
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_UP         36
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_CH1        37
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_UP         38
#define DMAMUX_CxCR_DMAREQ_ID_AES_IN           39
#define DMAMUX_CxCR_DMAREQ_ID_AES_OUT          40
#define DMAMUX_CxCR_DMAREQ_ID_SUBGHZSPI_RX     41
#define DMAMUX_CxCR_DMAREQ_ID_SUBGHZSPI_TX     42
/**@}*/

/* --- DMAMUX_RGxCR values ----------------------------------- */

/** @defgroup dmamux_rgxcr_sig_id SIGID DMA request trigger input selected
@{*/
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE0       0
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE1       1
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE2       2
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE3       3
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE4       4
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE5       5
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE6       6
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE7       7
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE8       8
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE9       9
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE10      10
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE11      11
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE12      12
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE13      13
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE14      14
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE15      15
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT0      16
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT1      17
#define DMAMUX_RGxCR_SIG_ID_LPTIM1_OUT       18
#define DMAMUX_RGxCR_SIG_ID_LPTIM2_OUT       19
#define DMAMUX_RGxCR_SIG_ID_LPTIM3_OUT       20
/**@}*/

/**@}*/
