#pragma once

#include <stdexcept>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define PINT unsigned int
#define PCHAR unsigned char

class SimplePng
{
public:
	SimplePng(int Width, int Height)
		: m_Width(Width), m_Height(Height)
	{
		m_Data = new unsigned char[m_Width * m_Height * 3];
	}

	void PutPixel(PINT x, PINT y,  PCHAR r, PCHAR b, PCHAR g, bool FlipX = true, bool FlipY = true)
	{
		if (x >= m_Width || y >= m_Height)
			throw std::out_of_range("Coords out of range");
		x = FlipX ? m_Width - x - 1 : x;
		y = FlipY ? m_Height - y - 1: y;
		int id = (x + y * m_Width) * 3;
		m_Data[id] = r;
		m_Data[id + 1] = g;
		m_Data[id + 2] = b;
	}

	void SaveToDisk(const char* Path)
	{
		stbi_write_png(Path, m_Width, m_Height, 3, m_Data, 0);
	}

	~SimplePng()
	{
		if (m_Data != nullptr)
		{
			delete[] m_Data;
			m_Data = nullptr;
		}
	}

private:
	int m_Width, m_Height;
	unsigned char* m_Data;
};