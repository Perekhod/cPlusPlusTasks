#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

class Book {
public:
    Book(std::string title, std::string author) : title_(std::move(title)), author_(std::move(author)) {}

    const std::string& getTitle () const { return title_    ; }
    const std::string& getAuthor() const { return author_   ; }

private:
    std::string title_;
    std::string author_;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        books_.emplace_back(std::make_unique<Book>(title, author));
    }

    void removeBook(const std::string& title) {
        auto it = std::find_if(books_.begin(), books_.end(), [&title](const auto& book) {
            return book->getTitle() == title;
            });

        if (it == books_.end()) {
            throw std::runtime_error("BookNotFoundException");
        }

        books_.erase(it);
    }

    void displayBooks() const {
        std::cout << "���������� �������� ��������� �����:" << std::endl;
        for (const auto& book : books_) {
            std::cout << "��������: " << book->getTitle() << ", �����: " << book->getAuthor() << std::endl;
        }
    }

private:
    std::vector<std::unique_ptr<Book>> books_;
};

int main() {
    setlocale(LC_ALL, "ru");

    Library library;

    library.addBook("1984", "George Orwell");
    library.addBook("����� � ���", "��� �������");

    library.displayBooks();

    try {
        library.removeBook("����� ������");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}
