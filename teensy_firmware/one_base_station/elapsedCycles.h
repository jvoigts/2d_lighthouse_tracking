#ifndef elapsedCycles_h
#define elapsedCycles_h
#ifdef __cplusplus

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/* Class for CPU clycle resolution timing */
/* Conversions between cycles and nanosecons are safe up to 100 mS */

class elapsedCycles
{
private:
unsigned long cyccount;
public:
elapsedCycles(void) { ARM_DEMCR |= ARM_DEMCR_TRCENA; ARM_DWT_CTRL |= 1; cyccount = ARM_DWT_CYCCNT; }
elapsedCycles(unsigned long val) { ARM_DWT_CTRL |= 1; cyccount = ARM_DWT_CYCCNT - val; }
elapsedCycles(const elapsedCycles &orig) { ARM_DWT_CTRL |= 1; cyccount = orig.cyccount; }
operator unsigned long () const { return ARM_DWT_CYCCNT - cyccount; }
elapsedCycles & operator = (const elapsedCycles &rhs) { cyccount = rhs.cyccount; return *this; }
elapsedCycles & operator = (unsigned long val) { cyccount = ARM_DWT_CYCCNT - val; return *this; }
elapsedCycles & operator -= (unsigned long val) { cyccount += val ; return *this; }
elapsedCycles & operator += (unsigned long val) { cyccount -= val ; return *this; }
elapsedCycles operator - (int val) const { elapsedCycles r(*this); r.cyccount += val; return r; }
elapsedCycles operator - (unsigned int val) const { elapsedCycles r(*this); r.cyccount += val; return r; }
elapsedCycles operator - (long val) const { elapsedCycles r(*this); r.cyccount += val; return r; }
elapsedCycles operator - (unsigned long val) const { elapsedCycles r(*this); r.cyccount += val; return r; }
elapsedCycles operator + (int val) const { elapsedCycles r(*this); r.cyccount -= val; return r; }
elapsedCycles operator + (unsigned int val) const { elapsedCycles r(*this); r.cyccount -= val; return r; }
elapsedCycles operator + (long val) const { elapsedCycles r(*this); r.cyccount -= val; return r; }
elapsedCycles operator + (unsigned long val) const { elapsedCycles r(*this); r.cyccount -= val; return r; }
static unsigned long ns2cycles(unsigned long ns) {return (ns*(F_CPU/8000000UL))/125UL; }
static unsigned long cycles2ns(unsigned long cycles) {return (cycles*125UL)/(F_CPU/8000000UL); }
};

#endif // __cplusplus
#endif // elapsedCycles_h
