/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, Image
 * Date: 18/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <cstdlib>

class Image
{
private:
	int width, height;
	int** imageData;
public:
	Image(int width, int height, int** imageData)
	{
		this->width = width;
		this->height = height;
		this->imageData = new int*[height];
		for (int i = 0; i < height; ++i)
		{
			this->imageData[i] = new int[width];
			for (int j = 0; j < width; ++j)
			{
				this->imageData[i][j] = imageData[i][j];
			}
		}
	}
	Image(Image& copyImage)
	{
		this->width = copyImage.width;
		this->height = copyImage.height;
		this->imageData = new int*[height];
		for (int i = 0; i < height; ++i)
		{
			this->imageData[i] = new int[width];
			for (int j = 0; j < width; ++j)
			{
				this->imageData[i][j] = copyImage.imageData[i][j];
			}
		}
	}
	~Image()
	{
	    for (int i = 0; i < height; ++i)
	    {
	        delete[] imageData[i];
	    }
	    delete[] imageData;
	}

	void display()
	{
		for (int i = 0;  i < this->height; i++)
		{
			for (int j = 0; j < this->width; ++j)
			{
				std::cout << imageData[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void updateData()
	{
		for (int i = 0;  i < this->height; i++)
		{
			for (int j = 0; j < this->width; ++j)
			{
				if (this->imageData[i][j] <= 0)
					this->imageData[i][j] = rand() % 255 + 1;
			}
		}
	}
};

int main()
{
	srand(time(NULL));
	int testData[2][3] = 
	{
		{0, 3, 4},
		{5, 6, 7}
	};
	int** data = new int*[2];
	for (int i = 0;  i < 2; i++)
	{
		data[i] = new int[3];
		for (int j = 0; j < 3; ++j)
		{
			data[i][j] = testData[i][j];
		}
	}
	Image myImage(3, 2, data);
	
	Image copyImage(myImage);

	std::cout << "Original Image: " << std::endl;
	myImage.display();

	std::cout << "Copied Image: " << std::endl;
	copyImage.display();

	myImage.updateData();
	std::cout << "After Change: " << std::endl;
	std::cout << "Original Image: " << std::endl;
	myImage.display();

	std::cout << "Copied Image: " << std::endl;
	copyImage.display();
}