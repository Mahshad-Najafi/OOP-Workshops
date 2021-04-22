/*
	Name:           Mahshad Najafi Ragheb
	Date:           2021-04-14
	The copy assignment operator is borrowed from Navpreet Singh.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace sdds {
	Line::operator const char* () const {
		return m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		if (m_value)
			delete[] m_value;

		m_value = new char[strlen(lineValue) + 1];
		strcpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}
	void TextFile::setEmpty() {
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}
	void TextFile::setFilename(const char* fname, bool isCopy) {
		if (!isCopy) {
			m_filename = new char[strlen(fname) + 1];
			strcpy(m_filename, fname);
		}
		else {
			m_filename = new char[strlen(fname) + 3];
			strcpy(m_filename, "C_");
			strcat(m_filename, fname);
		}
	}
	void TextFile::setNoOfLines() {
		ifstream fileIn(m_filename);
		char c;
		m_noOfLines = 0;
		while (fileIn.get(c)) {
			if (c == '\n')
				m_noOfLines++;
		}
		m_noOfLines++;
		if (m_noOfLines == 0) {
			if (m_filename) {
				delete[] m_filename;
				m_filename = nullptr;
			}
		}
	}
	void TextFile::loadText() {
		if (m_filename) {
			m_textLines = new Line[m_noOfLines];
			ifstream fileIn(m_filename);
			string line;
			int lineNo = 0;
			while (getline(fileIn, line)) {
				m_textLines[lineNo].m_value = new char[line.size() + 1];
				strcpy(m_textLines[lineNo].m_value, line.c_str());
				lineNo++;
			}
			m_noOfLines = lineNo;
			fileIn.close();
		}
	}
	void TextFile::saveAs(const char* fileName)const {
		ofstream fileOut(fileName);
		for (unsigned i = 0; i < m_noOfLines; i++) {
			fileOut << (const char*)m_textLines[i] << endl;
		}
		fileOut.close();
	}
	TextFile::TextFile(unsigned pageSize) {
		setEmpty();
		m_pageSize = pageSize;
	}
	TextFile::TextFile(const char* filename, unsigned pageSize) {
		m_pageSize = pageSize;

		if (filename != nullptr) {
			ifstream infile(filename);
			if (infile.good()) {
				setFilename(filename);
				setNoOfLines();
				loadText();
			}
			infile.close();
		}
	}
	TextFile::TextFile(const TextFile& source) {
		m_pageSize = source.m_pageSize;
		setEmpty();
		if (source) {
			setFilename(source.m_filename, true);
			source.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
	}
	// copy operator function written by Mahshad:
	//TextFile& TextFile::operator=(const TextFile& source) {
	//	if (m_textLines != nullptr && source.m_textLines != nullptr) {
	//		delete[] m_textLines;
	//		m_textLines = nullptr;
	//		for (unsigned i = 0; i < m_noOfLines; i++) {
	//			if (strlen(m_textLines[i].m_value) != strlen(source.m_textLines[i].m_value)) {
	//				delete[] m_textLines[i].m_value;
	//				m_textLines[i].m_value = new char[strlen(source.m_textLines[i].m_value) + 1];
	//			}
	//			strcpy(m_textLines[i].m_value, source.m_textLines[i].m_value);
	//		}
	//		source.saveAs(m_filename);
	//		setNoOfLines();
	//		loadText();
	//	}
	//	return *this;
	//}

	//The copy assignment operator is borrowed from Navpreet Singh.
	TextFile& TextFile::operator=(const TextFile& source)
	{

		if (source.m_textLines != nullptr && m_textLines != nullptr)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			source.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
		return *this;
	}
	TextFile::~TextFile() {
		delete[] m_textLines;
		delete[] m_filename;
	}
	std::ostream& TextFile::view(std::ostream& ostr)const {
		char c;
		if (m_filename == nullptr) {
			return ostr;
		}
		ostr << m_filename << endl;
		for (unsigned i = 0; i < strlen(m_filename); i++) {
			ostr << "=";
		}
		ostr << endl;
		for (unsigned i = 0; i < m_noOfLines; i++) {
			if (i % m_pageSize == 0 && i != 0) {
				ostr << "Hit ENTER to continue...";
				cin.get(c);
				ostr << endl;
			}
			ostr << (const char*)m_textLines[i] << endl;
		}
		return ostr;
	}
	std::istream& TextFile::getFile(std::istream& istr) {
		string s;
		istr >> s;
		m_filename = new char[s.size() + 1];
		strcpy(m_filename, s.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}
	TextFile::operator bool()const {
		return (m_filename != nullptr) ? true : false;
	}
	unsigned TextFile::lines()const {
		return m_noOfLines;
	}
	const char* TextFile::name()const {
		return m_filename;
	}
	const char* TextFile::operator[](unsigned index)const {
		if (m_filename == nullptr) {
			return nullptr;
		}
		else {
			index = index - (index / m_noOfLines) * m_noOfLines;
			return m_textLines[index];
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}
	std::istream& operator>>(std::istream& istr, TextFile& text) {
		return text.getFile(istr);
	}
}
