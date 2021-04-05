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

#ifndef LIBOPENCM3_RNG_H
#define LIBOPENCM3_RNG_H

#include <libopencm3/stm32/common/rng_common_v1.h>

/**@{*/

/* --- Random number generator registers ----------------------------------- */

/* Health Test Control register */
#define RNG_HTCR		MMIO32(RNG_BASE + 0x10)

/* --- RNG_HTCR values ------------------------------------------------------- */

/* Magic */
#define RNG_HTCR_MAGIC			(0x17590ABC)

/* Validation */
#define RNG_HTCR_VALIDATION		(0x0000AA74)

/* --- RNG_CR values ------------------------------------------------------- */

/* RNG configlock */
#define RNG_CR_CONFIGLOCK		(1 << 31)

/* RNG conditioning soft reset */
#define RNG_CR_CONDRST			(1 << 30)

/* RNG non NIST compliant */
#define RNG_CR_NISTC			(1 << 12)

/* RNG clock error detection */
#define RNG_CR_CED				(1 << 5)

/* RNG CONFIG1 value field */
#define RNG_CR_CONFIG1_MASK		(0x3f)
#define RNG_CR_CONFIG1_SHIFT	(20)

/* RNG CONFIG2 value field */
#define RNG_CR_CONFIG2_MASK		(0x7)
#define RNG_CR_CONFIG2_SHIFT	(13)

/* RNG CONFIG3 value field */
#define RNG_CR_CONFIG3_MASK		(0xf)
#define RNG_CR_CONFIG3_SHIFT	(8)

/* RNG clockdiv value field */
#define RNG_CR_CLKDIV_MASK		(0xf)
#define RNG_CR_CLKDIV_SHIFT		(16)

/**@}*/

#endif
