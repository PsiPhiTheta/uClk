#ifndef __DELAYS_H
#define __DELAYS_H

/* C18 cycle-count delay routines. */

/* Delay of exactly 1 Tcy */
#define Delay1TCY() _delay(1)

/* Delay of exactly 10 Tcy */
#define Delay10TCY() _delay(10)

/* Delay1TCYx */
void Delay1TCYx(unsigned char);

/* Delay10TCYx
 * Delay multiples of 10 Tcy
 * Passing 0 (zero) results in a delay of 2560 cycles.
 */
void Delay10TCYx(unsigned char);

/* Delay100TCYx
 * Delay multiples of 100 Tcy
 * Passing 0 (zero) results in a delay of 25,600 cycles.
 */
void Delay100TCYx(unsigned char);

/* Delay1KTCYx
 * Delay multiples of 1000 Tcy
 * Passing 0 (zero) results in a delay of 256,000 cycles.
 */
void Delay1KTCYx(unsigned char);

/* Delay10KTCYx
 * Delay multiples of 10,000 Tcy
 * Passing 0 (zero) results in a delay of 2,560,000 cycles.
 */
void Delay10KTCYx(unsigned char);

#endif
