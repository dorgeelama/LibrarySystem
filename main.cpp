#include<iostream>

int menu(){
  int choice = -1;
  while (choice == -1){
    std::cout << "Library Menu:\n";
    std::cout << "1) add_book\n";
    std::cout << "2) search_books_by_prefix\n";
    std::cout << "3) search_books_by_prefix\n";
    std::cout << "4) print_who_borrowed_book_by_name\n";
    std::cout << "5) print_library_by_id\n";
    std::cout << "6) print_library_by_name\n";
    std::cout << "7) add_user\n";
    std::cout << "8) user_borrow_book\n";
    std::cout << "9) user_return_book\n";
    std::cout << "10) Exit\n";


    std::cin >> choice;


    if(!(1<= choice <= 10)){
      std::cout << "Invalid choice. Try again\n";
      choice = -1;
    }
  }
  return choice;
}


void hospital_system(){
  while (true){
    int choice = menu();
    if(choice == 1){
      std::cout << "adding book\n";
    }
    else if (choice == 2){
      std::cout << "search_books_by_prefix\n";
    }
    else if (choice == 3){

    }
    else if (choice == 4){

    }
    else if (choice == 5){

    }
    else if (choice == 6){

    }
    else if (choice == 7){

    }
    else if (choice == 8){

    }
    else if (choice == 9){

    }
    else if (choice == 10){
      break;
    }
  }
}




int main() {
  hospital_system();
  return 0;
}
