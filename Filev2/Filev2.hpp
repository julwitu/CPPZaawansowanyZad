#pragma once
#include <fstream>

class File
{
public:
	enum class OpenMode {
		WRITE, //out | app
		READ //in
	};

	File(const std::string& filePath, OpenMode openMode); //w c-torze otwieramy plik (in, out | app)
	~File(); //w d-torze zamykamy plik


	//operatorory << >> s� rzadkim przypadkiem w kt�rym zaprzyja�nianie ma sens
	//poniewa� z obowi�zku s� deklarowane poza klas�, a korzystamy z nich tak jakby by�y w tej klasie
	//sama idea zaprzyja�niania jest "�liska", poniewa� omija mechanizmy enkapsulacji
	template<typename T>
	friend const File& operator<<(const File& file, T data);

	template<typename T>
	friend const File& operator>>(const File& file, T data);

	//T readValue();
	//writeValue(T);

private:
	std::fstream _filestream;
};

template<typename T>
const File& operator<<(const File& file, T data)
{
	if (READ)
		throw std::invalid_argument;
}

template<typename T>
const File& operator>>(const File& file, T data)
{
	if (WRITE)
		throw std::invalid_argument;
}