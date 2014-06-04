//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


#include <gpio.h>
#include <core.h>



//-------------------------------------------------------------------------
int main ( void )
{
    unsigned int ra;


    //ra=gpio_getgpfseln(16);
    //ra=GET32(GPFSEL1);
    //ra&=~(7<<18);
    //ra|=1<<18;
    //PUT32(GPFSEL1,ra);
    gpio_setgpfseln(16,GPIOFSEL_OUTPUT);

    while(1)
    {
        PUT32(GPSET0,1<<16);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
        PUT32(GPCLR0,1<<16);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
    }
    return(0);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------




//-------------------------------------------------------------------------
//
// Copyright (c) 2012 David Welch dwelch@dwelch.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------
