/** @defgroup comp_defines COMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32WLxx
 * Comparator module</b>
 *
 * @ingroup STM32WLxx_defines
 *
 *LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define COMP1	0
#define COMP2	1

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define COMP_CSR(i)			MMIO32(COMP_BASE + (i)*4)
#define COMP1_CSR			COMP_CSR(COMP1)
#define COMP2_CSR			COMP_CSR(COMP2)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* COMP_CSR Values ----------------------------------------------------------*/

#define COMPx_CSR_LOCK			(1 << 31)
#define COMPx_CSR_VALUE			(1 << 30)

#define COMPx_CSR_INMESEL_SHIFT	25
#define COMPx_CSR_INMESEL		(3 << COMPx_CSR_INMESEL_SHIFT)
#define COMP1_CSR_INMESEL_PA10	(0 << COMPx_CSR_INMESEL_SHIFT)
#define COMP1_CSR_INMESEL_PA11	(1 << COMPx_CSR_INMESEL_SHIFT)
#define COMP1_CSR_INMESEL_PA15	(2 << COMPx_CSR_INMESEL_SHIFT)
#define COMP2_CSR_INMESEL_PB2	(0 << COMPx_CSR_INMESEL_SHIFT)
#define COMP2_CSR_INMESEL_PA10	(1 << COMPx_CSR_INMESEL_SHIFT)
#define COMP2_CSR_INMESEL_PA11	(2 << COMPx_CSR_INMESEL_SHIFT)

#define COMPx_CSR_SCALEN		(1 << 23)
#define COMPx_CSR_BRGEN			(1 << 22)

#define COMPx_CSR_BLANKING_SHIFT		20
#define COMPx_CSR_BLANKING				(7 << COMPx_CSR_BLANKING_SHIFT)
#define COMPx_CSR_BLANKING_TIM1_OC5		(1 << COMPx_CSR_BLANKING_SHIFT)
#define COMPx_CSR_BLANKING_TIM2_OC3		(2 << COMPx_CSR_BLANKING_SHIFT)

#define COMPx_CSR_HYST_SHIFT	16
#define COMPx_CSR_HYST			(3 << COMPx_CSR_HYST_SHIFT)
#define COMPx_CSR_HYST_NO		(0 << COMPx_CSR_HYST_SHIFT)
#define COMPx_CSR_HYST_LOW		(1 << COMPx_CSR_HYST_SHIFT)
#define COMPx_CSR_HYST_MED		(2 << COMPx_CSR_HYST_SHIFT)
#define COMPx_CSR_HYST_HIGH		(3 << COMPx_CSR_HYST_SHIFT)

#define COMPx_CSR_POLARITY		(1 << 15)
#define COMPx_CSR_WINMODE		(1 << 9)

#define COMPx_CSR_INPSEL_SHIFT	7
#define COMPx_CSR_INPSEL		(3 << COMPx_CSR_INPSEL_SHIFT)
#define COMP1_CSR_INPSEL_PB4	(0 << COMPx_CSR_INPSEL_SHIFT)
#define COMP1_CSR_INPSEL_PB2	(1 << COMPx_CSR_INPSEL_SHIFT)
#define COMP2_CSR_INPSEL_PB4	(0 << COMPx_CSR_INPSEL_SHIFT)
#define COMP2_CSR_INPSEL_PB1	(1 << COMPx_CSR_INPSEL_SHIFT)
#define COMP2_CSR_INPSEL_PA15	(2 << COMPx_CSR_INPSEL_SHIFT)

#define COMPx_CSR_INMSEL_SHIFT	4
#define COMPx_CSR_INMSEL		(7 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_1_4	(0 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_1_2	(1 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_3_4	(2 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_VREF	(3 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_DAC1	(4 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_PB3	(6 << COMPx_CSR_INMSEL_SHIFT)
#define COMPx_CSR_INMSEL_GPIO	(7 << COMPx_CSR_INMSEL_SHIFT)

#define COMPx_CSR_PWRMODE_SHIFT	2
#define COMPx_CSR_PWRMODE		(3 << COMPx_CSR_PWRMODE_SHIFT)
#define COMPx_CSR_PWRMODE_HS	(0 << COMPx_CSR_PWRMODE_SHIFT)
#define COMPx_CSR_PWRMODE_MS	(1 << COMPx_CSR_PWRMODE_SHIFT)
#define COMPx_CSR_PWRMODE_MS1	(2 << COMPx_CSR_PWRMODE_SHIFT)
#define COMPx_CSR_PWRMODE_ULP	(3 << COMPx_CSR_PWRMODE_SHIFT)

#define COMPx_CSR_EN			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS
/**@}*/

#endif
