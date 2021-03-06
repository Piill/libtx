# Libtx

Libtx is a simple bit-banged UART lib for the ATTiny85.
As the name suggests, it's only for outputting data.

It's main usage is to help me create other, more exiting products.

It uses the basic [8-N-1](https://en.wikipedia.org/wiki/8-N-1) configuration.

## Usage

Simply copy the sources to your project and include the header.
Use the function `libtx_setup` first to setup the registers.
Use `libtx_write` to send a byte or `libtx_write_string` to send a NULL-terminated string.


To change the baudrate or tx-pin, change the definitions in the header file.

# License

MIT License

Copyright (c) 2017 Pil Eghoff

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
