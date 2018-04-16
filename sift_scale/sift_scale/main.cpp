#include <stdio.h>
#include "sift_scale.h"

int main(void)
{
	IplImage* img = cvLoadImage("../sift_scale/image/teabuff.bmp",1);
	
	IplImage*   init_img = NULL;
	IplImage*** gauss_pyr = NULL;
	
	int intvs    = SIFT_INTVLS;
	int img_dbl  = SIFT_IMG_DBL;
	double sigma = SIFT_SIGMA;

	init_img = create_init_img(img, img_dbl, sigma);
	// �������ÿ���еĲ���S��ͨ������ͼ��Ŀ�߽�Сֵȡ������ȷ��
	int octvs = log((float)MIN(init_img->width, init_img->height)) / log((float)2) - 2;
	// �����߶ȿռ亯��
	gauss_pyr = build_gauss_pyr(init_img, octvs, intvs, sigma);

	if (save_guass_pyrmid(gauss_pyr, octvs, intvs, true))
	{
		printf("the store of building scale space success...\n");
	}
	else
	{
		printf("the store of building scale space failed...\n");
	}

	system("pause");

	return 0;
}