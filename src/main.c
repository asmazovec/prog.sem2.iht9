/*  MIT License
 *
 *  Copyright (c) 2020 Alexander Mazovets

 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:

 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.

 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
*/


#include <stdio.h>
#include "consupport.h"


int main () {
    fprintf (stdout, "Дан символьный файл F. Переписать в файл G сначала все нечётные его символы, а затем все чётные в обратном порядке.\n\n");
    
    FILE* input;
    if (NULL==(input = fopen (input_word (NULL, 256, stdin, stdout, "Укажите расположение файла: "), "r"))) {
        fprintf (stdout, "Файл не существует\n\n");
    }
    FILE* output = fopen ("G", "w");
    
    int size = 0;
    int key;
    do {
        key = fgetc (input);
        if (key!=EOF) size++;
        key = fgetc (input);
        if (key!=EOF) size++;
        fputc (key, output);
    } while (key!=EOF);
    size--;
    
    if (1==(size % 2)) {
        fseek (input, -2, SEEK_END);
        size--;
        fputc (fgetc (input), output);
    }

    while (size>0) {
        fseek (input, -3, SEEK_CUR);
        size -= 2;
        fputc (fgetc (input), output);
    }

    fclose (output);
    fclose (input);
    return 0;
}
