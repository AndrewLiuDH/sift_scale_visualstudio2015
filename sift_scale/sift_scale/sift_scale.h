#pragma once
/** -- @file
-- This Project's Code is Part of Rob Hess SIFT Code.
-- Functions for detecting SIFT Scale Space.

-- For more information, refer to:

-- Lowe, D.  Distinctive image features from scale-invariant keypoints.
   <EM>International Journal of Computer Vision, 60</EM>, 2 (2004),
   pp.91--110.

-- Copyright (C) 2006  Rob Hess <hess@eecs.oregonstate.edu>
   Note: The SIFT algorithm is patented in the United States and cannot be
   used in commercial products without a license from the University of
   British Columbia.  For more information, refer to the file LICENSE.ubc
   that accompanied this distribution.

-- @version 1.1.1-20070330
*/
#include <opencv2\opencv.hpp>

/* ������ͼ����и�˹ģ��ȥ������ */
#define SIFT_INIT_SIGMA 0.5

/** �Ƿ�˫��ͼ���С�����߶ȿռ� */
#define SIFT_IMG_DBL 1

/** ��˹ģ����ʼ���߶�ϵ�� */
#define SIFT_SIGMA 1.6

/** Ĭ��ÿһ���еĲ��� */
#define SIFT_INTVLS 3

// ������ͼ������²���
IplImage* downsample(IplImage*);

// ������˹�������߶ȿռ�
IplImage*** build_gauss_pyr(IplImage*, int, int, double);

// ������ʼ��ͼ��
IplImage* create_init_img(IplImage* img, int img_dbl, double sigma);

// ��ͼ��ת��Ϊ�Ҷ�32Fģʽ��
IplImage* convert_to_gray32(IplImage* img);

// ���湹���߶ȿռ�ĸ�˹������ͼ��
bool save_guass_pyrmid(IplImage ***guass_pyd, int octvs, int intvls, bool save_pyrmid=false);