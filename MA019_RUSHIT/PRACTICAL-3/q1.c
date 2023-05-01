#include <stdio.h>
#include <string.h>

struct Book {
   char book_name[50];
   char author_name[50];
   float price;
   int pages;
};

void display_book_info(struct Book *book_ptr);
void display_all_book_info(struct Book *book_list, int num_books);

int main() {
   struct Book books[100];
   struct Book *book_ptr;
   int i, num_books;

   printf("Enter number of books: ");
   scanf("%d", &num_books);

   for (i = 0; i < num_books; i++) {
      printf("\nEnter details of Book %d\n", i+1);
      book_ptr = &books[i];

      printf("Enter Book Name: ");
      scanf("%s", book_ptr->book_name);

      printf("Enter Author Name: ");
      scanf("%s", book_ptr->author_name);

      printf("Enter Price: ");
      scanf("%f", &book_ptr->price);

      printf("Enter Pages: ");
      scanf("%d", &book_ptr->pages);
   }

   printf("\n\nDetails of Books starting with 'D'\n");
   for (i = 0; i < num_books; i++) {
      if (books[i].book_name[0] == 'D') {
         book_ptr = &books[i];
         display_book_info(book_ptr);
      }
   }

   printf("\n\nAll Books Information\n");
   display_all_book_info(books, num_books);

   return 0;
}

void display_book_info(struct Book *book_ptr) {
   printf("\nBook Name: %s", book_ptr->book_name);
   printf("\nAuthor Name: %s", book_ptr->author_name);
   printf("\nPrice: %.2f", book_ptr->price);
   printf("\nPages: %d", book_ptr->pages);
}

void display_all_book_info(struct Book *book_list, int num_books) {
   struct Book *book_ptr;
   int i;

   for (i = 0; i < num_books; i++) {
      book_ptr = &book_list[i];
      printf("\n\nDetails of Book %d", i+1);
      display_book_info(book_ptr);
   }
}
