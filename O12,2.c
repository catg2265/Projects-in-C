#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 10
#define TITLE_MAX 50
#define AUTHOR_MAX 40
#define PUBLISHER_MAX 20

struct book
{
    char title[TITLE_MAX], author[AUTHOR_MAX], publisher[PUBLISHER_MAX];
    int publishing_year;
    int university_text_book;
};
typedef struct book book;

book make_book(char *title, char *author, char *publisher, int year, int text_book);
void prnt_book(book b);
int qsort_title(const void *i1, const void *i2);
int qsort_books_by_kind_and_year(const void *i, const void *i2);

void sort_books_by_title(book shelf[], int last)
{
    qsort(shelf, last + 1, sizeof(book), qsort_title);
}

int qsort_title(const void *i1, const void *i2)
{
    book *a = (book *)i1;
    book *b = (book *)i2;
    int i = 0;

    while (a->title[i] == b->title[i])
    {
        i++;
    }
    
    if (a->title[i] < b->title[i]){
        return -1;
    }
    else if (a->title[i] > b->title[i]){
        return 1;
    }
    else{ 
        return 0;
    }
}

int qsort_books_by_kind_and_year(const void *i1, const void *i2)
{
    book *a = (book *)i1;
    book *b = (book *)i2;

    if (a->university_text_book == 0 && a->university_text_book == 0)
    {
        if (a->publishing_year < b->publishing_year){
            return -1;
        }
        else if (a->publishing_year > b->publishing_year){
            return 1;
        }
        else{ 
            return 0;
        }
    } else if (a->university_text_book == 1 && a->university_text_book == 0)
    {
        return -1;
    } else if (a->university_text_book == 0 && a->university_text_book == 1)
    {
        return -1;
    } else
    {
        if (a->publishing_year < b->publishing_year){
            return -1;
        }
        else if (a->publishing_year > b->publishing_year){
            return 1;
        }
        else{ 
            return 0;
        }
    }

}


int main(void)
{
    book shelf[MAX_BOOKS];
    int i;

    shelf[0] =
        make_book("Problem Solving and Program Design in C", "Hanly and Koffman",
                  "Pearson", 2010, 1);

    shelf[1] =
        make_book("C by Disssection", "Kelley and Pohl",
                  "Addison Wesley", 2001, 1);

    shelf[2] =
        make_book("The C Programming Language", "Kernighan og Ritchie",
                  "Prentice Hall", 1988, 1);

    shelf[3] =
        make_book("Pelle Erobreren", "Martin Andersen Nexoe",
                  "Gyldendal", 1910, 0);

    shelf[4] = shelf[3];
    strcpy(shelf[4].title, "Ditte Menneskebarn");
    shelf[4].publishing_year = 1917;

    for (i = 0; i <= 4; i++)
        prnt_book(shelf[i]);
    
    printf("\n--------------------------------------------\n");

    sort_books_by_title(shelf, 4);
    for (i = 0; i <= 4; i++)
        prnt_book(shelf[i]);

    printf("\n--------------------------------------------\n");

    qsort(shelf, 5, sizeof(book), qsort_books_by_kind_and_year);
    for (i = 0; i <= 4; i++)
        prnt_book(shelf[i]);

    return 0; 
}

book make_book(char *title, char *author, char *publisher,
               int year, int text_book)
{
    book result;
    strcpy(result.title, title);
    strcpy(result.author, author);
    strcpy(result.publisher, publisher);
    result.publishing_year = year;
    result.university_text_book = text_book;

    return result;
}

void prnt_book(book b)
{
    char *yes_or_no;

    yes_or_no = (b.university_text_book ? "yes" : "no");
    printf("Title: %s\n"
           "Author: %s\n"
           "Publisher: %s\n"
           "Year: %4i\n"
           "University text book: %s\n\n",
           b.title, b.author, b.publisher,
           b.publishing_year, yes_or_no);
}
