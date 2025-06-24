﻿/*
 * Copyright (C) 2005-2024 X584 developers
 *
 * This file is part of X584.
 *
 * X584 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * X584 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with X584. If not, see <https://www.gnu.org/licenses/>.
 */

//---------------------------------------------------------------------------
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include "K584core.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

#define INSTR_COUNT 50
InstrDesc iSet[INSTR_COUNT] = {
    //формат 1
    {TYPE_ALU, 2, {OP_REG, OP_WR},                  OP_REG,     L"aaaa00rrr", true,      L"Операция над РОН и РР, результат в РОН"},                          //00
    {TYPE_ALU, 2, {OP_REG, OP_WR},                  OP_WR,      L"aaaa01rrr", true,      L"Операция над РОН и РР, результат в РР"},                           //01
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_OUT,     L"aaaa11000", false,     L"Подать на шину выхода результат операции над шиной входа и РР"},   //02
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_WR,      L"aaaa11001", false,     L"Операция над шиной входа и РР, результат в РР"},                   //03
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_WR,      L"aaaa11011", true,      L"Операция над шиной входа и РРР, результат в РР"},                  //04
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_XWR,     L"aaaa11100", true,      L"Операция над шиной входа и РР, результат в РРР"},                  //05
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_XWR,     L"aaaa11110", true,      L"Операция над шиной входа и РРР, результат в РРР"},                 //06
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_OUT,     L"aaaa11111", true,      L"Подать на шину выхода результат операции над шиной входа и РРР"},  //07
    //формат 2
    {TYPE_SUM, 3, {OP_REG, OP_WR, OP_CARRY},        OP_XWR,     L"001110rrr", true,      L"Поместить в РРР сумму РОНа, РР и ПАЛУ"},                           //08
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_WR,      L"010010rrr", true,      L"Поместить в РР сумму РОНа, шины входа и ПАЛУ"},                    //09
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_XWR,     L"010110rrr", true,      L"Поместить в РРР сумму РОНа, шины входа и ПАЛУ"},                   //10
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_REG,     L"011110rrr", true,      L"Прибавить к РОНу сумму шины входа и ПАЛУ"},                        //11
    {TYPE_SUM, 3, {OP_REG, OP_XWR, OP_CARRY},       OP_WR,      L"110010rrr", true,      L"Поместить в РР сумму РОНа, РРР и ПАЛУ"},                           //12
    {TYPE_SUM, 3, {OP_REG, OP_XWR, OP_CARRY},       OP_XWR,     L"110110rrr", true,      L"Прибавить к РРР сумму РОНа и ПАЛУ"},                               //13
    {TYPE_SUM, 2, {OP_XWR, OP_CARRY},               OP_REG,     L"111010rrr", true,      L"Присвоить РОНу сумму РРР и ПАЛУ"},                                 //14
    {TYPE_SUM, 3, {OP_WR, OP_IN, OP_CARRY},         OP_XWR,     L"001111010", true,      L"Поместить в РРР сумму РР, шины входа и ПАЛУ"},                     //15
    {TYPE_SUM, 3, {OP_WR, OP_IN, OP_CARRY},         OP_OUT,     L"011111010", true,      L"Подать на шину выхода сумму РР, шины входа и ПАЛУ"},               //16
    {TYPE_SUM, 3, {OP_XWR, OP_IN, OP_CARRY},        OP_WR,      L"110011010", true,      L"Поместить в РР сумму РРР, шины входа и ПАЛУ"},                     //17
    {TYPE_SUM, 3, {OP_XWR, OP_IN, OP_CARRY},        OP_XWR,     L"110111010", true,      L"Прибавить к РРР сумму шины входа и ПАЛУ"},                         //18
    {TYPE_SUM, 2, {OP_XWR, OP_CARRY},               OP_OUT,     L"111011010", true,      L"Подать на шину выхода сумму РРР и ПАЛУ"},                          //19
    //формат 3
    {TYPE_SUM, 1, {OP_IN},                          OP_REG,     L"111110rrr", true,      L"Переслать слово из шины входа в РОН"},                             //20
    {TYPE_SUM, 1, {OP_REG},                         OP_OUT,     L"000010rrr", true,      L"Переслать значение РОНа на шину выхода"},                          //21
    {TYPE_SUM, 1, {OP_REG},                         OP_XWR,     L"000110rrr", true,      L"Переслать значение РОНа в РРР"},                                   //22
    {TYPE_SUM, 1, {OP_IN},                          OP_WR,      L"011010xxx", true,      L"Переслать слово из шины входа в РР"},                              //23
    {TYPE_SUM, 1, {OP_IN},                          OP_WR,      L"011011010", true,      L"Переслать слово из шины входа в РР"},                              //24
    {TYPE_SUM, 1, {OP_IN},                          OP_XWR,     L"000111010", true,      L"Переслать слово из шины входа в РРР"},                             //25
    {TYPE_SUM, 1, {OP_IN},                          OP_OUT,     L"111111010", true,      L"Переслать слово с шины входа на шину выхода"},                     //26
    {TYPE_SUM, 1, {OP_IN},                          OP_OUT,     L"000011010", true,      L"Переслать слово с шины входа на шину выхода"},                     //27
    //формат 4
    {TYPE_SCL, 4, {OP_WR, OP_IN | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   L"100011010", true,      L"Сдвиг циклический левый двойной точности суммы РР, инверсного значения шины входа и ПАЛУ"},     //28
    {TYPE_SCL, 3, {OP_WR, OP_IN, OP_CARRY},         OP_WRXWR,   L"100111010", true,      L"Сдвиг циклический левый двойной точности суммы РР, шины входа и ПАЛУ"},                         //29
    {TYPE_SCL, 4, {OP_WR, OP_REG | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   L"100010rrr", true,      L"Сдвиг циклический левый двойной точности суммы РР, инверсного значения РОНа и ПАЛУ"},           //30
    {TYPE_SCL, 3, {OP_WR, OP_REG, OP_CARRY},        OP_WRXWR,   L"100110rrr", true,      L"Сдвиг циклический левый двойной точности суммы РР, РОНа и ПАЛУ"},                               //31
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"101010xxx", true,      L"Сдвиг арифметический правый двойной точности суммы РР и ПАЛУ"},                                 //32
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"101011010", true,      L"Сдвиг арифметический правый двойной точности суммы РР и ПАЛУ"},                                 //33
    {TYPE_SAR, 4, {OP_WR, OP_IN | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   L"001011010", true,      L"Сдвиг арифметический правый двойной точности суммы РР, инверсного значения шины входа и ПАЛУ"}, //34
    {TYPE_SAR, 3, {OP_WR, OP_IN, OP_CARRY},         OP_WRXWR,   L"101111010", true,      L"Сдвиг арифметический правый двойной точности суммы РР, шины входа и ПАЛУ"},                     //35
    {TYPE_SAR, 4, {OP_WR, OP_REG | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   L"001010rrr", true,      L"Сдвиг арифметический правый двойной точности суммы РР, инверсного значения РОНа и ПАЛУ"},       //36
    {TYPE_SAR, 3, {OP_WR, OP_REG, OP_CARRY},        OP_WRXWR,   L"101110rrr", true,      L"Сдвиг арифметический правый двойной точности суммы РР, РОНа и ПАЛУ"},                           //37
    //формат 5
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WR,      L"000011101", true,      L"Поместить в РР сдвиг арифметический правый суммы РР и ПАЛУ"},      //38
    {TYPE_SCR, 2, {OP_WR, OP_CARRY},                OP_WR,      L"x00111101", true,      L"Поместить в РР сдвиг циклический правый суммы РР и ПАЛУ"},         //39
    {TYPE_SAL, 2, {OP_WR, OP_CARRY},                OP_WR,      L"001011101", true,      L"Поместить в РР сдвиг арифметический левый суммы РР и ПАЛУ"},       //40
    {TYPE_SCL, 2, {OP_WR, OP_CARRY},                OP_WR,      L"x01111101", true,      L"Поместить в РР сдвиг циклический левый суммы РР и ПАЛУ"},          //41
    {TYPE_SLR, 2, {OP_WR, OP_CARRY},                OP_WR,      L"100011101", true,      L"Поместить в РР сдвиг логический правый суммы РР и ПАЛУ"},          //42
    {TYPE_SLL, 2, {OP_WR, OP_CARRY},                OP_WR,      L"101011101", true,      L"Поместить в РР сдвиг логический левый суммы РР и ПАЛУ"},           //43
    //формат 6
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"010011101", true,      L"Сдвиг арифметический правый двойной точности суммы РР и ПАЛУ"},    //44
    {TYPE_SCR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"x10111101", true,      L"Сдвиг циклический правый двойной точности суммы РР и ПАЛУ"},       //45
    {TYPE_SAL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"011011101", true,      L"Сдвиг арифметический левый двойной точности суммы РР и ПАЛУ"},     //46
    {TYPE_SCL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"x11111101", true,      L"Сдвиг циклический левый двойной точности суммы РР и ПАЛУ"},        //47
    {TYPE_SLR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"110011101", true,      L"Сдвиг логический правый двойной точности суммы РР и ПАЛУ"},        //48
    {TYPE_SLL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   L"111011101", true,      L"Сдвиг логический левый двойной точности суммы РР и ПАЛУ"}          //49
};

K584::K584(int _BitsCount)
: BitsCount(_BitsCount), WR(0), XWR(0), BufDA(0), BufXWR(0)
{
    memset(Reg, 0, sizeof(Reg));
    BitMask = (1 << BitsCount) - 1;
    //вычисляем битовые маски микроинструкций
    for (int i = 0; i < INSTR_COUNT; i++) {
        iSet[i].BitMask = 0;
        for (int j = 0; j < 9; j++)
            if (iSet[i].BitField[j] == L'0' || iSet[i].BitField[j] == L'1') {
                iSet[i].BitValue |= (iSet[i].BitField[j] == L'1' ? 1 : 0) << (8 - j);
                iSet[i].BitMask |= 1 << (8 - j);
            }
    }
}

void K584::Reset()
{
    memset(Reg, 0, sizeof(Reg));
    WR = XWR = 0;
    BufDA = BufXWR = 0;
}

void K584::FormatOp(unsigned Op, wchar_t *A, wchar_t *B, wchar_t *Str)
{
    if (Op & 0x08)
        //логические операции
        switch (Op & 0x07) {
        case 0x00:
            swprintf(Str, L"%s and %s", A, B);
            break;
        case 0x01:
            swprintf(Str, L"%s xor %s", A, B);
            break;
        case 0x02:
            swprintf(Str, L"!(%s xor %s)", A, B);
            break;
        case 0x03:
            swprintf(Str, L"!%s and %s", A, B);
            break;
        case 0x04:
            swprintf(Str, L"%s and !%s", A, B);
            break;
        case 0x05:
            swprintf(Str, L"%s or !%s", A, B);
            break;
        case 0x06:
            swprintf(Str, L"!%s or %s", A, B);
            break;
        case 0x07:
            swprintf(Str, L"%s or %s", A, B);
            break;
        }
    else
        //арифметические операции
        switch (Op & 0x07) {
        case 0x00:
            wcscpy(Str, L"!П");
            break;
        case 0x01:
            swprintf(Str, L"%s - %s - 1 + П", B, A);
            break;
        case 0x02:
            swprintf(Str, L"%s - %s - 1 + П", A, B);
            break;
        case 0x03:
            swprintf(Str, L"%s + %s + П", A, B);
            break;
        case 0x04:
            swprintf(Str, L"%s + П", B);
            break;
        case 0x05:
            swprintf(Str, L"!%s + П", B);
            break;
        case 0x06:
            swprintf(Str, L"%s + П", A);
            break;
        case 0x07:
            swprintf(Str, L"!%s + П", A);
            break;
        }
}

unsigned K584::Adc(unsigned op1, unsigned op2, unsigned Carry, unsigned &OutFlags)
{
    unsigned OldCarry = Carry &= 0x01;
    OutFlags = F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    //потетрадное сложение
    for (int i = 0; i < BitsCount / 4; i++) {
        Carry = ((op1 >> i * 4 & 0x0F) + (op2 >> i * 4 & 0x0F) + Carry) >> 4 & 0x01;
        OutFlags |= Carry ? F_C0 << i : 0;
    }
    OutFlags |= Carry ? F_CO : 0;
    return op1 + op2 + OldCarry & BitMask;
}

unsigned K584::ExecuteOp(unsigned Op, unsigned A, unsigned B, unsigned InFlags, unsigned &OutFlags)
{
    unsigned Carry = (InFlags & F_CI) != 0;
    OutFlags = F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    if (Op & 0x08)
        //логические операции
        switch (Op & 0x07) {
        case 0x00:
            return A & B;
        case 0x01:
            return A ^ B;
        case 0x02:
            return ~(A ^ B);
        case 0x03:
            return ~A & B;
        case 0x04:
            return A & ~B;
        case 0x05:
            return A | ~B;
        case 0x06:
            return ~A | B;
        case 0x07:
            return A | B;
        }
    else
        //арифметические операции
        switch (Op & 0x07) {
        case 0x00:
            return Carry ? 0 : BitMask;
        case 0x01:
            return Adc(~A, B, Carry, OutFlags);
        case 0x02:
            return Adc(A, ~B, Carry, OutFlags);
        case 0x03:
            return Adc(A, B, Carry, OutFlags);
        case 0x04:
            return Adc(B, 0, Carry, OutFlags);
        case 0x05:
            return Adc(~B, 0, Carry, OutFlags);
        case 0x06:
            return Adc(A, 0, Carry, OutFlags);
        case 0x07:
            return Adc(~A, 0, Carry, OutFlags);
        }
    return 0;
}

void K584::Shift(InstrType Op, int ResType, unsigned &Result, unsigned InFlags, unsigned &OutFlags, unsigned OldWRSign)
{
    OutFlags |= F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    Result &= BitMask;
    XWR &= BitMask;
    unsigned bit, sign = Result & 1 << (BitsCount - 1);
    switch (Op) {
    case TYPE_SAL:
        OutFlags ^= sign ? F_INVSL1 : 0;
        Result <<= 1;
        if (ResType == OP_WRXWR) {
            bit = (InFlags & F_P0 ? XWR >> (BitsCount - 1) : XWR >> (BitsCount - 2)) & 0x01;
            XWR <<= 1;
            Result |= bit;
            OutFlags ^= bit ? F_INVSL2 | F_INVSR1 : 0;
            if (!(InFlags & F_P0))
                XWR = (XWR & ~(1 << (BitsCount - 1))) | (Result & 1 << (BitsCount - 1));
        }
        break;

    case TYPE_SAR:
        bit = Result & 0x01;
        OutFlags ^= bit ? F_INVSR1 : 0;
        Result = Result >> 1 | OldWRSign;
        if (ResType == OP_WRXWR) {
            OutFlags ^= (XWR & 0x01 ? F_INVSR2 : 0) | (bit ? F_INVSL2 : 0);
            XWR >>= 1;
            if (InFlags & F_P0)
                XWR |= bit << (BitsCount - 1);
            else {
                XWR |= OldWRSign;
                XWR = (XWR & ~(1 << (BitsCount - 2))) | (bit << (BitsCount - 2));
            }
        }
        break;

    case TYPE_SLL:
        OutFlags ^= sign ? F_INVSL1 : 0;
        Result <<= 1;
        if (ResType == OP_WRXWR) {
            bit = XWR >> (BitsCount - 1) & 0x01;
            OutFlags ^= bit ? F_INVSL2 | F_INVSR1 : 0;
            XWR <<= 1;
            Result |= bit;
        }
        break;

    case TYPE_SLR:
        bit = Result & 0x01;
        OutFlags ^= bit ? F_INVSR1 : 0;
        Result >>= 1;
        if (ResType == OP_WRXWR) {
            OutFlags ^= (XWR & 0x01 ? F_INVSR2 : 0) | (bit ? F_INVSL2 : 0);
            XWR >>= 1;
            XWR |= bit << (BitsCount - 1);
        }
        break;

    case TYPE_SCL:
        if (ResType == OP_WRXWR) {
            bit = XWR >> (BitsCount - 1) & 0x01;
            OutFlags ^= (sign ? F_INVSL1 | F_INVSR2 : 0) | (bit ? F_INVSR1 | F_INVSL2 : 0);
            Result = Result << 1 | bit;
            XWR = XWR << 1 | sign >> (BitsCount - 1);
        } else {
            OutFlags ^= sign ? F_INVSL1 | F_INVSR1 : 0;
            Result = Result << 1 | sign >> (BitsCount - 1);
        }
        break;

    case TYPE_SCR:
        sign = Result & 0x01;
        if (ResType == OP_WRXWR) {
            bit = XWR & 0x01;
            OutFlags ^= (sign ? F_INVSR1 | F_INVSL2 : 0) | (bit ? F_INVSR2 | F_INVSL1 : 0);
            Result = Result >> 1 | bit << (BitsCount - 1);
            XWR = XWR >> 1 | sign << (BitsCount - 1);
        } else {
            OutFlags ^= sign ? F_INVSL1 | F_INVSR1 : 0;
            Result = Result >> 1 | sign << (BitsCount - 1);
        }
        break;

    default:
        break;
    }
}

bool K584::Format(unsigned MI, wchar_t *Str, bool FormatALU, bool FormatReg, bool ShowCarry)
{
    wchar_t fmt[][10] = {L"РР", L"РРР", L"РОН%d", L"ШИНвх", L"ШИНвых", L"П", L"(РР, РРР)", L"1"};
    wchar_t shift[][5] = {L"САЛ(", L"САП(", L"СЛЛ(", L"СЛП(", L"СЦЛ(", L"СЦП("};
    if (!FormatReg)
        wcscpy(fmt[2], L"РОН");
    //ищем микроинструкцию в базе данных
    wchar_t A[16], B[16], C[32];
    for (int i = 0; i < INSTR_COUNT; i++)
        if ((MI & iSet[i].BitMask) == iSet[i].BitValue) {
            //результат операции
            swprintf(Str, fmt[iSet[i].Result], MI & 0x07);
            wcscat(Str, L" := ");
            switch (iSet[i].Type) {
            case TYPE_SUM:
                //формируем список операндов, разделенных знаками
                for (int j = 0; j < iSet[i].OpCount; j++) {
                    if (j)
                        wcscat(Str, iSet[i].Operands[j] & F_MINUS ? L" - " : L" + ");
                    swprintf(A, fmt[iSet[i].Operands[j] & F_MMASK], MI & 0x07);
                    wcscat(Str, A);
                }
                break;

            case TYPE_ALU:
                //форматируем бинарную операцию
                swprintf(A, fmt[iSet[i].Operands[0]], MI & 0x07);
                swprintf(B, fmt[iSet[i].Operands[1]], MI & 0x07);
                if (FormatALU)
                    FormatOp(MI >> 5, A, B, C);
                else
                    swprintf(C, L"%s н %s", A, B);
                wcscat(Str, C);
                break;

            default:
                //определяем код операции
                wcscat(Str, shift[iSet[i].Type - TYPE_SAL]);
                //формируем список операндов, разделенных знаками
                for (int j = 0; j < iSet[i].OpCount; j++) {
                    if (j)
                        wcscat(Str, iSet[i].Operands[j] & F_MINUS ? L" - " : L" + ");
                    swprintf(A, fmt[iSet[i].Operands[j] & F_MMASK], MI & 0x07);
                    wcscat(Str, A);
                }
                //закрываем скобку
                wcscat(Str, iSet[i].Result == OP_WRXWR ? L", РРР)" : L")");
                break;
            }
            //определяем, надо ли форматировать перенос
            if (ShowCarry && (MI & ATTR_CUSED) != 0)
                wcscat(Str, MI & ATTR_CARRY ? L" (П=1)" : L" (П=0)");
            return true;
        }
    //неподдерживаемая инструкция
    wcscpy(Str, NOP_TEXT);
    return false;
}

bool K584::FindOperand(int Index, int Type, unsigned MI)
{
    //ищем указанный операнд в списке
    for (int i = 0; i < iSet[Index].OpCount; i++)
        if ((iSet[Index].Operands[i] & F_MMASK) == Type) {
            if (iSet[Index].Type == TYPE_ALU) {
                //операция АЛУ - проверяем, используется ли реально операнд
                unsigned op = MI >> 5 & 0x0F;
                if (op & 0x08)
                    //логическая операция - все бинарные
                    return true;
                switch (op) {
                case 0x01:
                case 0x02:
                case 0x03:
                    return true;
                case 0x04:
                case 0x05:
                    return (iSet[Index].Operands[1] & F_MMASK) == Type;
                case 0x06:
                case 0x07:
                    return (iSet[Index].Operands[0] & F_MMASK) == Type;
                default:
                    return false;
                }
            } else {
                return true;
            }
        }
    //если операнд - ПАЛУ, то проверяем, не встречается ли он в арифметической операции
    if (Type == OP_CARRY && iSet[Index].Type == TYPE_ALU)
        return (MI >> 5 & 0x0F) < 8;
    return false;
}

bool K584::Execute(unsigned MI, unsigned DI, unsigned &DO, unsigned &DA, unsigned InFlags, unsigned &OutFlags)
{
    unsigned Carry = (InFlags & F_CI) != 0;
    unsigned OldWRSign = 0;
    //ищем микроинструкцию в базе данных
    for (int i = 0; i < INSTR_COUNT; i++)
        if ((MI & iSet[i].BitMask) == iSet[i].BitValue) {
            //формируем список операндов
            unsigned Ops[3] = {0, 0, 0};
            int count = 0;
            for (int j = 0; j < iSet[i].OpCount; j++) {
                switch (iSet[i].Operands[j] & F_MMASK) {
                case OP_WR:
                    Ops[count++] = WR;
                    break;
                case OP_XWR:
                    Ops[count++] = XWR;
                    break;
                case OP_REG:
                    Ops[count++] = Reg[MI & 0x07];
                    break;
                case OP_IN:
                    Ops[count++] = DI;
                    break;
                case OP_CARRY:
                    Ops[2] = Carry;
                    break;
                default:
                    continue;
                }
                if (iSet[i].Operands[j] & F_MINUS)
                    Ops[count - 1] = ~Ops[count - 1];
            }
            //получаем адрес приемника
            unsigned *result;
            switch (iSet[i].Result) {
            case OP_WR:
            case OP_WRXWR:
                result = &WR;
                break;
            case OP_XWR:
                result = &XWR;
                break;
            case OP_REG:
                result = Reg + (MI & 0x07);
                break;
            case OP_OUT:
                result = &DO;
                break;
            }
            //выполняем операцию
            switch (iSet[i].Type) {
            case TYPE_SUM:
                //суммируем операнды
                *result = Adc(Ops[0], Ops[1], Ops[2], OutFlags);
                break;
            case TYPE_ALU:
                //выполняем бинарную операцию
                *result = ExecuteOp(MI >> 5, Ops[0], Ops[1], InFlags, OutFlags);
                break;
            default:
                // берём старый знак РР
                OldWRSign = WR & (1 << (BitsCount - 1));
                //суммируем операнды
                *result = Adc(Ops[0], Ops[1], Ops[2], OutFlags);
                //производим нужный сдвиг
                Shift(iSet[i].Type, iSet[i].Result, *result, InFlags, OutFlags, OldWRSign);
            }
            *result &= BitMask;
            //инкрементируем программный счетчик
            if (!(InFlags & F_INVPC))
                Reg[7] = Reg[7] + (InFlags & F_INC ? 2 : 1) & BitMask;
            //выдаем содержимое буферных регистров шина адреса и XWR
            DA = BufDA;
            OutFlags |= BufXWR & 0x01 ? F_XWR0 : 0;
            OutFlags |= BufXWR & 1 << (BitsCount - 1) ? F_XWR3 : 0;
            //выдаем старшие биты шин A и B
            OutFlags |= (Ops[0] & 1 << (BitsCount - 1) ? F_A3 : 0) |
                        (Ops[1] & 1 << (BitsCount - 1) ? F_B3 : 0);
            //заполняем буферные регистры
            BufDA = InFlags & F_PR ? Reg[7] : (iSet[i].OutWR ? WR : XWR);
            BufXWR = XWR;
            return true;
        }
    return false;
}

