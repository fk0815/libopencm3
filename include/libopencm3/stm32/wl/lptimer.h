/** @defgroup lptimer_defines LPTIM Defines
 *
 * @ingroup STM32WLxx_defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32WLxx Low Power Timer</b>
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

#ifndef LIBOPENCM3_LPTIMER_H
#define LIBOPENCM3_LPTIMER_H
/**@{*/

#include <libopencm3/stm32/common/lptimer_common_all.h>

#define LPTIM_OR(tim_base)		MMIO32((tim_base) + 0x20)
#define LPTIM_RCR(tim_base)		MMIO32((tim_base) + 0x28)

/** @defgroup lptim_reg_base Low Power Timer register base addresses
@{*/
#define LPTIM1				LPTIM1_BASE
#define LPTIM2				LPTIM2_BASE
#define LPTIM3				LPTIM3_BASE
/**@}*/

#define LPTIM1_OR			LPTIM_OR(LPTIM1_BASE)
#define LPTIM2_OR			LPTIM_OR(LPTIM2_BASE)
#define LPTIM1_RCR			LPTIM_RCR(LPTIM1_BASE)
#define LPTIM2_RCR			LPTIM_RCR(LPTIM2_BASE)

#define LPTIM3_ISR			LPTIM_ISR(LPTIM3_BASE)
#define LPTIM3_ICR			LPTIM_ICR(LPTIM3_BASE)
#define LPTIM3_IER			LPTIM_IER(LPTIM3_BASE)
#define LPTIM3_CFGR			LPTIM_CFGR(LPTIM3_BASE)
#define LPTIM3_CR			LPTIM_CR(LPTIM3_BASE)
#define LPTIM3_CMP			LPTIM_CMP(LPTIM3_BASE)
#define LPTIM3_ARR			LPTIM_ARR(LPTIM3_BASE)
#define LPTIM3_CNT			LPTIM_CNT(LPTIM3_BASE)
#define LPTIM3_OR			LPTIM_OR(LPTIM3_BASE)
#define LPTIM3_RCR			LPTIM_RCR(LPTIM3_BASE)

/** @defgroup lptim_isr LPTIM_ISR Interrupt and Status Register
 *@{*/

/** LPTIM_ISR_UE update event */
#define LPTIM_ISR_UE			(1 << 7)

/** LPTIM_ISR_REPOK repetition register update OK */
#define LPTIM_ISR_REPOK			(1 << 8)

/**@}*/

/** @defgroup lptim_icr LPTIM_ICR Interrupt Clear Register
 *@{*/

/** LPTIM_ICR_UECF update event */
#define LPTIM_ICR_UECF			(1 << 7)

/** LPTIM_ICR_REPOKCF repetition register update OK */
#define LPTIM_ICR_REPOKCF		(1 << 8)

/**@}*/

/** @defgroup lptim_ier LPTIM_IER Interrupt Enable Register
 *@{*/

/** LPTIM_IER_UEIE update event */
#define LPTIM_IER_UEIE			(1 << 7)

/** LPTIM_IER_REPOKIE repetition register update OK */
#define LPTIM_IER_REPOKIE		(1 << 8)

/**@}*/

/** @defgroup lptim_cfgr_trigsel LPTIM_CFGR TRIGSEL Trigger selector
 *@{*/
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG5	(5 << LPTIM_CFGR_TRIGSEL_SHIFT)
/**@}*/

/** @defgroup lptim_cr LPTIM_CR Control Register
 *@{*/

/** COUNTRST: LPTIM Counter reset */
#define LPTIM_CR_COUNTRST		(1 << 3)

/** RSTARE: Reset after read enable */
#define LPTIM_CR_RSTARE			(1 << 4)

/**@}*/

/** @defgroup lptim_or LPTIM_OR Option Register
 *@{*/

/** OR_0: Option Bit 0 */
#define LPTIM_OR_OR_0			(1 << 0)

/** OR_1: Option Bit 1 */
#define LPTIM_OR_OR_1			(1 << 1)

/**@}*/

BEGIN_DECLS

END_DECLS

/**@}*/
#endif
