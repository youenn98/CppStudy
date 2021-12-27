#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <typename T> class grid {
public:
	grid();
	grid(size_t row, size_t line);

	void clear();
	void resize(size_t row, size_t line);

	size_t numRows() const;
	size_t numLines() const;
	const T& getAt(size_t row, size_t line) const;
	T& getAt(size_t row, size_t line);
	void setAt(size_t row, size_t line, T val);

	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	iterator rowBegin(size_t row);
	const_iterator rowBegin(size_t row) const;
	iterator rowEnd(size_t row);
	const_iterator rowEnd(size_t row) const;

	class MutableReference {
	public:
		friend class grid;
		MutableReference(grid* owner, size_t row) :owner(owner), row(row) { ; }
		T& operator[](size_t col);

	private:
		grid* const owner;
		const size_t row;
	};
	MutableReference operator[](size_t row);


	class ImMutableReference {
	public:
		friend class grid;
		ImMutableReference(grid* owner, size_t row) :owner(owner), row(row) { ; }
		const T& operator[](size_t col) const;
	private:
		const grid* const owner;
		const size_t row;
	};
	ImMutableReference  operator[](size_t row) const;

	bool operator<(const grid& other) const;
	bool operator>(const grid& other) const;
	bool operator<=(const grid& other) const;
	bool operator>=(const grid& other) const;
	bool operator==(const grid& other) const;
	bool operator!=(const grid& other) const;
private:
	size_t rows, lines;
	vector<T> elemts;

};

template <typename T> grid<T>::grid() :rows(0), lines(0) { ; }
template <typename T> grid<T>::grid(size_t row, size_t line) : rows(row), lines(line), elemts(row* line) { ; }

template <typename T>
void grid<T>::clear() {
	resize(0, 0);
}
template <typename T>
void grid<T>::resize(size_t row, size_t line) {
	elemts.assign(row * line, typename vector<T>::value_type());
	this->rows = row;
	this->lines = line;
}

template <typename T>
size_t grid<T>::numRows() const {
	return rows;
}

template <typename T>
size_t grid<T>::numLines() const {
	return lines;
}

template <typename T>
const T& grid<T>::getAt(size_t row, size_t line) const {
	return elemts[row * lines + line];
}

template <typename T>
T& grid<T>::getAt(size_t row, size_t line) {
	return elemts[row * lines + line];
}

template <typename T>
void grid<T>::setAt(size_t row, size_t line, T val) {
	elemts[row * lines + line] = val;
}

template<typename T>
typename grid<T>::iterator grid<T>::begin()
{
	return elemts.begin();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::begin() const
{
	return elemts.begin();
}

template<typename T>
typename grid<T>::iterator grid<T>::end()
{
	return elemts.end();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::end() const
{
	return elemts.end();
}

template<typename T>
typename grid<T>::iterator grid<T>::rowBegin(size_t row)
{
	return elemts.begin() + row * numLines();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::rowBegin(size_t row) const
{
	return elemts.begin() + row * numLines();
}

template<typename T>
typename grid<T>::iterator grid<T>::rowEnd(size_t row)
{
	return elemts.begin() + row * (numLines() + 1) - 1;
}

template<typename T>
typename grid<T>::const_iterator grid<T>::rowEnd(size_t row) const
{
	return elemts.begin() + row * (numLines() + 1) - 1;
}

template<typename T>
typename grid<T>::MutableReference grid<T>::operator[](size_t row)
{
	return MutableReference(this, row);
}

template<typename T>
typename grid<T>::ImMutableReference grid<T>::operator[](size_t row) const
{
	return ImMutableReference(this, row);
}

template<typename T>
bool grid<T>::operator<(const grid& other) const
{
	if (this->numRows() != other.numRows()) {
		return this->numRows() < other.numRows();
	}
	if (this->numLines() != other.numLines()) {
		return this->numLines() < other.numLines();
	}

	return lexicographical_compare(this->begin(), this->end(), other.begin(), other.end());
}

template<typename T>
bool grid<T>::operator>(const grid& other) const
{
	return (!(*this < other) && !(*this == other));
}

template<typename T>
bool grid<T>::operator<=(const grid& other) const
{
	return !(*this > other);
}

template<typename T>
bool grid<T>::operator>=(const grid& other) const
{
	return !(*this < other);
}

template<typename T>
bool grid<T>::operator==(const grid& other) const
{
	if (this->numRows() != other.numRows()) {
		return false;
	}
	if (this->numLines() != other.numLines()) {
		return false;
	}

	return equal(this->begin(), this->end(), other.begin(), other.end());
}

template<typename T>
bool grid<T>::operator!=(const grid& other) const
{
	return !(*this == other);
}

template<typename T>
T& grid<T>::MutableReference::operator[](size_t col)
{
	return owner->getAt(this->row, col);
}

template<typename T>
const T& grid<T>::ImMutableReference::operator[](size_t col) const
{
	return owner->getAt(this->row, col);
}

int main() {
	grid<int> gd(2, 2);
	grid<int> gd2(3, 3);
	gd.setAt(1, 1, 1);
	gd.resize(3, 3);

	auto it = gd.rowBegin(1);
	it++;
	cout << *it << endl;
	gd.setAt(2, 2, 1);
	cout << gd[2][2] << endl;
	cout << (gd >= gd2) << endl;
}

