/** @defgroup spi_defines SPI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32WLxx SPI</b>
 *
 * @ingroup STM32WLxx_defines
 *
 * @version 1.0.0
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

#ifndef LIBOPENCM3_SPI_H
#define LIBOPENCM3_SPI_H

#include <libopencm3/stm32/common/spi_common_v2.h>

/** @defgroup spi_reg_base SPI Register base address
 * @ingroup spi_defines
 *
 * @{*/
#define SPI2S2				SPI2S2_BASE
#define SUBGHZSPI			SUBGHZSPI_BASE
/**@}*/

/* --- SPI_I2SCFGR values -------------------------------------------------- */

#define SPI_I2SCFGR_ASTRTEN			(1 << 12)

#endif
