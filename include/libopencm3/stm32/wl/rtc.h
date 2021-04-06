/** @defgroup rtc_defines RTC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32WLxx RTC</b>
 *
 * @ingroup STM32WLxx_defines
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

#ifndef LIBOPENCM3_RTC_H
#define LIBOPENCM3_RTC_H

#include <libopencm3/stm32/common/rtc_common_l1f024.h>

#undef RTC_CR
#define RTC_CR			MMIO32(RTC_BASE + 0x18)
#define RTC_ICSR		MMIO32(RTC_BASE + 0x0C)
#undef RTC_CALR
#define RTC_CALR		MMIO32(RTC_BASE + 0x28)
#undef RTC_ALRMAR
#define RTC_ALRMAR		MMIO32(RTC_BASE + 0x40)
#undef RTC_ALRMBR
#define RTC_ALRMBR		MMIO32(RTC_BASE + 0x48)
#define RTC_SR			MMIO32(RTC_BASE + 0x50)
#define RTC_MISR		MMIO32(RTC_BASE + 0x54)
#define RTC_SCR			MMIO32(RTC_BASE + 0x5C)
#define RTC_ALRABINR	MMIO32(RTC_BASE + 0x70)
#define RTC_ALRBBINR	MMIO32(RTC_BASE + 0x74)

/** @defgroup rtc_cr_values RTC control register (RTC_CR) values
 * @ingroup rtc_registers
 * @{*/

/**  RTC_OUT2 output enable */
#define RTC_CR_OUT2EN			(1<<31)

/** TAMPALRM output type */
#define RTC_CR_TAMPALRM_TYPE	(1<<30)

/** TAMPALRM pull-up enable */
#define RTC_CR_TAMPALRM_PU		(1<<29)

/** Tamper detection output enable on TAMPALRM */
#define RTC_CR_TAMPOE			(1<<26)

/** Activate timestamp on tamper detection event */
#define RTC_CR_TAMPTS			(1<<25)

/** timestamp on internal event enable */
#define RTC_CR_ITSE				(1<<24)

/** SSR underflow interrupt enable */
#define RTC_CR_SSRUIE			(1<<7)

/**@}*/

/** @defgroup rtc_wpr_values RTC write protection register (RTC_WPR) values
 * @ingroup rtc_registers
 * @{*/

/** WPR Key1 */
#define RTC_WPR_KEY1			(0xCA)

/** WPR Key2 */
#define RTC_WPR_KEY2			(0x53)

/**@}*/

/** @defgroup rtc_icsr_values RTC initialization control and status register (RTC_ICSR) values
 * @ingroup rtc_registers
 * @{*/
/** RECALPF: Recalib pending flag */
#define RTC_ICSR_RECALPF		(1<<16)

/** BCDU: BCD update (BIN = 10 or 11) */
#define RTC_ICSR_BCDU_SHIFT		(10)
#define RTC_ICSR_BCDU_MASK		(0x7)
#define RTC_ICSR_BDCU_SS_7_0	(0x0)
#define RTC_ICSR_BDCU_SS_8_0	(0x1)
#define RTC_ICSR_BDCU_SS_9_0	(0x2)
#define RTC_ICSR_BDCU_SS_10_0	(0x3)
#define RTC_ICSR_BDCU_SS_11_0	(0x4)
#define RTC_ICSR_BDCU_SS_12_0	(0x5)
#define RTC_ICSR_BDCU_SS_13_0	(0x6)
#define RTC_ICSR_BDCU_SS_14_0	(0x7)

/** BIN: Binary mode */
#define RTC_ICSR_BIN_SHIFT		(8)
#define RTC_ICSR_BIN_MASK		(0x3)
#define RTC_ICSR_BIN_BCD		(0x0)
#define RTC_ICSR_BIN_BINARY		(0x1)
#define RTC_ICSR_BIN_BCD_BIN	(0x2)
#define RTC_ICSR_BIN_BIN_BCD	(0x3)

/** INIT: Initialization mode */
#define RTC_ICSR_INIT			(1<<7)
/** INITF: Initialization flag */
#define RTC_ICSR_INITF			(1<<6)
/** RSF: Registers sync flag */
#define RTC_ICSR_RSF			(1<<5)
/** INITS: Init status flag */
#define RTC_ICSR_INITS			(1<<4)
/** SHPF: Shift operation pending */
#define RTC_ICSR_SHPF			(1<<3)
/** WUTWF: Wakeup timer write flag */
#define RTC_ICSR_WUTWF			(1<<2)
/**@}*/

#undef RTC_PRER_PREDIV_S_MASK
#define RTC_PRER_PREDIV_S_MASK	(0xffff)

/** @defgroup rtc_calr_values RTC calibration register (RTC_CALR) values
 * @ingroup rtc_registers
 * @{*/
#define RTC_CALR_LPCAL			(1 << 12)
/**@}*/

#define RTC_ALARXSSR_SSCLR		(1 << 31)
#undef RTC_ALARXSSR_MASKSS_MASK
#define RTC_ALARXSSR_MASKSS_MASK  (0x3f)

/** @defgroup rtc_sr_values RTC status register (RTC_SR) values
 * @ingroup rtc_registers
 * @{*/
/** SSRUF: SSR underflow flag */
#define RTC_SR_SSRUF			(1<<6)
/** ITSF: Internal timestamp flag */
#define RTC_SR_ITSF				(1<<5)
/** TSOVF: Timestamp overflow flag */
#define RTC_SR_TSOVF			(1<<4)
/** TSF: Timestamp flag */
#define RTC_SR_TSF				(1<<3)
/** WUTF: Wakeup timer flag */
#define RTC_SR_WUTF				(1<<2)
/** ALRBF: Alarm B flag */
#define RTC_SR_ALRBF			(1<<1)
/** ALRAF: Alarm A flag */
#define RTC_SR_ALRAF			(1<<0)
/**@}*/

/** @defgroup rtc_misr_values RTC masked interrupt status register (RTC_MISR) values
 * @ingroup rtc_registers
 * @{*/
/** SSRUMF: SSR underflow masked flag */
#define RTC_SR_SSRUMF			(1<<6)
/** ITSMF: Internal timestamp masked flag */
#define RTC_SR_ITSMF			(1<<5)
/** TSOVMF: Timestamp overflow masked flag */
#define RTC_SR_TSOVMF			(1<<4)
/** TSMF: Timestamp masked flag */
#define RTC_SR_TSMF				(1<<3)
/** WUTMF: Wakeup timer masked flag */
#define RTC_SR_WUTMF			(1<<2)
/** ALRBMF: Alarm B masked flag */
#define RTC_SR_ALRBMF			(1<<1)
/** ALRAMF: Alarm A masked flag */
#define RTC_SR_ALRAMF			(1<<0)
/**@}*/

/** @defgroup rtc_scr_values RTC status clear register (RTC_SCR) values
 * @ingroup rtc_registers
 * @{*/
/** CSSRUF: Clear SSR underflow flag */
#define RTC_SR_CSSRUF			(1<<6)
/** CITSF: Clear Internal timestamp flag */
#define RTC_SR_CITSF			(1<<5)
/** CTSOVF: Clear Timestamp overflow flag */
#define RTC_SR_CTSOVF			(1<<4)
/** CTSF: Clear Timestamp flag */
#define RTC_SR_CTSF				(1<<3)
/** CWUTF: Clear Wakeup timer flag */
#define RTC_SR_CWUTF			(1<<2)
/** CALRBF: Clear Alarm B flag */
#define RTC_SR_CALRBF			(1<<1)
/** CALRAF: Clear Alarm A flag */
#define RTC_SR_CALRAF			(1<<0)
/**@}*/

#endif
