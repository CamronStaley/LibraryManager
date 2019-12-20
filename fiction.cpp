#include "fiction.h"
//----------------------------------------------------------------------------
//print
//format and displays the fiction book stock, author, title, and year.
void Fiction::print() const {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << instock
        << setw(AUTHOR_OUTPUT_WIDTH) << author.substr(0, AUTHOR_MAX_LENGTH)
        << setw(TITLE_OUTPUT_WIDTH) << title.substr(0, TITLE_MAX_WIDTH)
        << year << endl;
}

//----------------------------------------------------------------------------
//setData
//reads author, title, and year from istr and sets the data accordingly. Also
//sets type to F and stock to 5 but can be set from the file
void Fiction::setData(istream& istr) {
    bookType = 'F';
    instock = 5;

    istr.get();
    getline(istr, author, ',');

    istr.get();
    getline(istr, title, ',');
    istr >> year;
}

//----------------------------------------------------------------------------
//partialSetData
//reads book presentation author and title from istr and 
//sets data accordingly (called by transaction class)
void Fiction::partialSetData(istream& istr) {
    bookType = 'F';

    istr.get();
    getline(istr, author, ',');
    
    istr.get();
    getline(istr, title, ',');
}

//----------------------------------------------------------------------------
//operator==
//returns true only if the author, and title are the same for both books
bool Fiction::operator==(const Book& other) const {
    const Fiction& temp = static_cast<const Fiction&>(other);//cast
    if (author != temp.author) { //check author
        return false;
    }
    else if (title != temp.title) { //check title
        return false;
    }
    else {
        return true;
    }
}

//----------------------------------------------------------------------------
//operator<
//sorts by author and then title. If this author alphabetically comes before
//the other author then returns true. If authors are equal and this title
//alphabetically comes before the other title return true. Otherwise return
//false
bool Fiction::operator<(const Book& other) const {
    const Fiction& temp = static_cast<const Fiction&>(other);//cast
    if (author < temp.author) { //check author
        return true;
    }
    else if (author == temp.author && title < temp.title) { //check title
        return true;
    }
    else {
        return false;
    }
}
//----------------------------------------------------------------------------
//printHeader
//displays the header for printing in library system
void Fiction::printHeader() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << "FICTION BOOKS " << endl;
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << "AVAIL"
        << setw(AUTHOR_OUTPUT_WIDTH) << "AUTHOR"
        << setw(TITLE_OUTPUT_WIDTH) << "TITLE"
        << "YEAR" << endl;
}

//----------------------------------------------------------------------------
//printPartial
//prints the partial data that is set in the transaction class.
//only prints the author, title, and year using setw
void Fiction::printPartial() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << setw(PAUTHOR_OUTPUT_WIDTH) << author.substr(0, PAUTHOR_MAX_LENGTH)
        << setw(PTITLE_OUTPUT_WIDTH) << title.substr(0, PTITLE_MAX_WIDTH)
        << year << endl;

}
