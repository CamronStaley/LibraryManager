#include "periodical.h"
//----------------------------------------------------------------------------
//print
//formats and displays the periodical stock, title, month and year.
void Periodical::print() const {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << instock
        << setw(TITLE_OUTPUT_WIDTH) << title.substr(0, TITLE_MAX_WIDTH)
        << setw(MONTH_OUTPUT_WIDTH) << month
        << year << endl;
}

//----------------------------------------------------------------------------
//setData
//reads from istream the title, month, year, and sets them accordingly. Also
//sets the type to P and the stock to 1 which could be set from file
void Periodical::setData(istream& istr) {
    bookType = 'P';
    instock = 1;

    istr.get();
    getline(istr, title, ',');

    istr >> month;
    istr >> year;
}
//----------------------------------------------------------------------------
//partialSetData
//reads book presentation author and title from istr and 
//sets data accordingly (called by transaction class)
void Periodical::partialSetData(istream& istr) {

    bookType = 'P';
    istr >> year;
    istr >> month;

    istr.get();
    getline(istr, title, ',');
}

//----------------------------------------------------------------------------
//operator==
//returns true only if the year, month, and title are the same for both books
bool Periodical::operator==(const Book& other) const {
    const Periodical& temp = static_cast<const Periodical&>(other);//cast
    if (year != temp.year || month != temp.month) { //check months
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
//sorts by year, then month and then title. If year is less returns true. 
//If year is same and month is less return true. If year and month are same
//and title is alphabetically before other title then return true. Otherwise
//return false
bool Periodical::operator<(const Book& other) const {
    const Periodical& temp = static_cast<const Periodical&>(other);//cast
    if (year < temp.year) { //check year
        return true;
    }
    else if (year == temp.year && month < temp.month) { //check month
        return true;
    }
    else if (year == temp.year && month == temp.month
        && title < temp.title) { //check title
        return true;
    }
    else {
        return false;
    }
}
//----------------------------------------------------------------------------
//printHeader
//prints the header for displaying in catagory
void Periodical::printHeader() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << "PERIODICALS BOOKS " << endl;
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << "AVAIL"
        << setw(TITLE_OUTPUT_WIDTH) << "TITLE"
        << setw(MONTH_OUTPUT_WIDTH) << "MONTH"
        << "YEAR" << endl;
}

//----------------------------------------------------------------------------
//printPartial
//prints the partial data that is set in the transaction class.
//only prints the title, month, and year using setw
void Periodical::printPartial() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << setw(PTITLE_OUTPUT_WIDTH) << title.substr(0, PTITLE_MAX_WIDTH)
        << setw(MONTH_OUTPUT_WIDTH) << month
        << year << endl;

}