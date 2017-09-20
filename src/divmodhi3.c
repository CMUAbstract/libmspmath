/* Libgcc Target specific implementation - Emulating div and mod.
   Copyright (C) 2012-2015 Free Software Foundation, Inc.
   Contributed by KPIT Cummins Infosystems Limited.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */
	 

/* Emulate the division and modulus operation.  */
/*
unsigned short udivmodhi4 (unsigned short num, unsigned short den, short modwanted)
{
  unsigned short bit = 1;
  unsigned short res = 0;

  while (den < num && bit && !(den & (1 << 15)))
    {
      den <<= 1;
      bit <<= 1;
    }
  while (bit)
    {
      if (num >= den)
	{
	  num -= den;
	  res |= bit;
	}
      bit >>= 1;
      den >>= 1;
    }

  if (modwanted)
    return num;
  return res;
}
*/
unsigned int divhi4 (unsigned int num, unsigned int den)
{
  unsigned int bit = 1;
  unsigned int res = 0;

  while (den < num && bit && !(den & (1 << 31)))
    {
      den <<= 1;
      bit <<= 1;
    }
  while (bit)
    {
      if (num >= den)
	{
	  num -= den;
	  res |= bit;
	}
      bit >>= 1;
      den >>= 1;
    }

  return res;
}

// Simulates multiplication. Note, NOT type safe... this will happily overflow
unsigned int mulhi4 (unsigned int a, unsigned int b)
{
	unsigned int i, accum;
	for (i = 0, accum = 0; i < b; i++){
		accum += a;
	}
	return accum;
}

short
__divhi3 (short a, short b)
{
  short neg = 0;
  short res;

  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }

  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }

  res = udivmodhi4 (a, b, 0);

  if (neg)
    res = -res;

  return res;
}

short
__modhi3 (short a, short b)
{
  short neg = 0;
  short res;

  if (a < 0)
    {
      a = -a;
      neg = 1;
    }

  if (b < 0)
    b = -b;

  res = udivmodhi4 (a, b, 1);

  if (neg)
    res = -res;

  return res;
}

short
__udivhi3 (short a, short b)
{
  return udivmodhi4 (a, b, 0);
}

short
__umodhi3 (short a, short b)
{
  return udivmodhi4 (a, b, 1);
}

int __mulsi3 (int a, int b)
{
	int neg = 0;
	int res = 0;
  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }

  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }
	res = mulhi4(a,b);
	if (neg)
		res = -res;

	return res;
}

int __divsi3 (int a, int b)
{
	int neg = 0;
	int res = 0;
  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }

  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }
	res = divhi4(a,b);
	if (neg)
		res = -res;

	return res;
}
