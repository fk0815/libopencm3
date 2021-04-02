/** @defgroup exti_defines EXTI Defines
 *
 * @ingroup STM32WLxx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32WLxx EXTI Control</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 **/
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

#ifndef LIBOPENCM3_EXTI_H
#define LIBOPENCM3_EXTI_H

#include <libopencm3/stm32/common/exti_common_all.h>

/* --- EXTI registers ------------------------------------------------------ */
#define EXTI_RTSR1			MMIO32(EXTI_BASE + 0x00)
#define EXTI_FTSR1			MMIO32(EXTI_BASE + 0x04)
#define EXTI_SWIER1			MMIO32(EXTI_BASE + 0x08)
#define EXTI_PR1			MMIO32(EXTI_BASE + 0x0C)
#define EXTI_RTSR2			MMIO32(EXTI_BASE + 0x20)
#define EXTI_FTSR2			MMIO32(EXTI_BASE + 0x24)
#define EXTI_SWIER2			MMIO32(EXTI_BASE + 0x28)
#define EXTI_PR2			MMIO32(EXTI_BASE + 0x2C)
#define EXTI_C1IMR1			MMIO32(EXTI_BASE + 0x80)
#define EXTI_C1EMR1			MMIO32(EXTI_BASE + 0x84)
#define EXTI_C1IMR2			MMIO32(EXTI_BASE + 0x90)
#define EXTI_C1EMR2			MMIO32(EXTI_BASE + 0x94)

#define EXTI_RTSR			EXTI_RTSR1
#define EXTI_FTSR			EXTI_FTSR1
#define EXTI_PR 			EXTI_PR1
#define EXTI_IMR			EXTI_C1IMR1
#define EXTI_EMR			EXTI_C1EMR1

/* EXTI number definitions */
#define EXTI38				(1 << 6)
#define EXTI40				(1 << 8)
#define EXTI42				(1 << 10)
#define EXTI43				(1 << 11)
#define EXTI44				(1 << 12)
#define EXTI45				(1 << 13)
#define EXTI46				(1 << 14)

#endif
