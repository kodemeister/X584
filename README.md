**English** | [Русский](README-ru.md)

# X584

X584 is a graphical simulator of Soviet-era [K584VM1](https://ru.wikipedia.org/wiki/%D0%9C%D0%B8%D0%BA%D1%80%D0%BE%D0%BF%D1%80%D0%BE%D1%86%D0%B5%D1%81%D1%81%D0%BE%D1%80%D0%BD%D0%B0%D1%8F_%D1%81%D0%B5%D0%BA%D1%86%D0%B8%D1%8F#%D0%A1%D0%B5%D1%80%D0%B8%D1%8F_584) 4-bit slice microprocessor (a clone of [Texas Instruments SBP0400](https://en.wikipedia.org/wiki/Texas_Instruments_SBP0400)).

> [!IMPORTANT]
> **This is the legacy version for Windows XP, Vista and 7. If you are looking for modern versions supporting Windows 10+, please check [branch 2.0](https://github.com/kodemeister/X584/tree/2.0).**

![Screenshot](Screenshot.png?raw=true)

## Features

* Simulation of 4 microprocessor slices that are cascaded to form 16-bit microprocessor.
* Drag-and-drop editing of microcode.
* Support for full 9-bit microinstruction set.
* Displaying and editing current microprocessor state.
* Integrated debugger with support for step-by-step execution and breakpoints.
* Conditional execution via special comment syntax.

## Building from source

1. Install C++ Builder 6.
2. Install Microsoft HTML Help Workshop.
> [!NOTE]
> It looks like Microsoft removed HTML Help Workshop from their website. You can still download it from the [web archive](https://web.archive.org/web/20200918004813/https://download.microsoft.com/download/0/A/9/0A939EF6-E31C-430F-A3DF-DFAE7960D564/htmlhelp.exe) or install it via Chocolatey.
3. Open `X584.bpr` in C++ Builder and build the project.
4. Open `Help\X584.hhp` in HTML Help Workshop and build the project.

The compiled executable and CHM help file will be located under `Build` directory.
