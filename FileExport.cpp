//---------------------------------------------------------------------------
#pragma hdrstop

#include "FileExport.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

TExportThread::TExportThread(bool CreateSuspended)
: TThread(CreateSuspended)
{
}

void __fastcall TExportThread::Execute()
{
    X584Form->WordItem->Enabled = false;
    //??????????? ? ???????? ?????????????
    CoInitialize(NULL);
    X584Form->WordApplication->Connect();
    //??????? ????? ???????? ? ????????? ???????? ??????????
    X584Form->WordApplication->Documents->Add(EmptyParam, EmptyParam, EmptyParam, EmptyParam);
    X584Form->WordDocument->ConnectTo(X584Form->WordApplication->ActiveDocument);
    X584Form->WordApplication->Options->CheckSpellingAsYouType = False;
    X584Form->WordApplication->Options->CheckGrammarAsYouType = False;
    //?????????? ?????????
    X584Form->WordApplication->Selection->Font->Size = 14;
    X584Form->WordApplication->Selection->Font->Bold = true;
    X584Form->WordApplication->Selection->ParagraphFormat->Alignment = wdAlignParagraphCenter;
    X584Form->WordApplication->Selection->TypeText(StringToOleStr(X584Form->Caption + "\n"));
    //?????????? ???? ? ????? ????????
    TDateTime dt = Now();
    X584Form->WordApplication->Selection->Font->Size = 12;
    X584Form->WordApplication->Selection->Font->Bold = false;
    X584Form->WordApplication->Selection->Font->Italic = true;
    X584Form->WordApplication->Selection->ParagraphFormat->Alignment = wdAlignParagraphLeft;
    X584Form->WordApplication->Selection->TypeText(StringToOleStr("\n???? ????????: " + DateToStr(dt) + "\n"));
    X584Form->WordApplication->Selection->TypeText(StringToOleStr("????? ????????: " + TimeToStr(dt) + "\n\n"));
    //?????????? ?????????? ???????????? ?????
    int count = MAX_ADDR - 1;
    while (count >= 0 && X584Form->Code[count] == NOP && X584Form->CodeListView->Items->Item[count]->SubItems->Strings[2] == "")
        count--;
    count++;
    //??????? ? ??????????? ???????
    X584Form->WordApplication->Selection->Font->Size = 12;
    X584Form->WordApplication->Selection->Font->Italic = false;
    TVariant start = X584Form->WordApplication->Selection->Start;
    X584Form->WordDocument->Tables->Add(X584Form->WordDocument->Range(start, EmptyParam),
        count + 1, 3, EmptyParam, EmptyParam);
    Table *table = X584Form->WordDocument->Tables->Item(1);
    table->Borders->set_Enable(true);
    table->Columns->Item(1)->Width = 50;
    table->Columns->Item(2)->Width = 250;
    //????????? ?????????
    AnsiString Head[3] = {"?????", "???????????????", "???????????"};
    for (int i = 0; i < 3; i++) {
        Range *range;
        table->Cell(1, i + 1)->get_Range(&range);
        range->ParagraphFormat->Alignment = wdAlignParagraphCenter;
        range->Font->set_Bold(true);
        range->InsertAfter(StringToOleStr(Head[i]));
    }
    //????????? ???? ???????
    for (int i = 0; i < count; i++)
        for (int j = 0; j < 3; j++) {
            Range *range;
            table->Cell(i + 2, j + 1)->get_Range(&range);
            range->ParagraphFormat->Alignment = j ? wdAlignParagraphLeft : wdAlignParagraphCenter;
            range->InsertAfter(StringToOleStr(X584Form->CodeListView->Items->Item[i]->SubItems->Strings[j]));
        }
    //?????????? ???????? ? ????????? ??????
    X584Form->WordApplication->set_Visible(true);
    X584Form->WordDocument->Disconnect();
    X584Form->WordApplication->Disconnect();
    X584Form->WordItem->Enabled = true;
    CoUninitialize();
}
