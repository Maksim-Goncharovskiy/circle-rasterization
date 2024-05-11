#pragma once
#ifndef BREZENHAM_CIRCLE_LIB_73
#define BREZENHAM_CIRCLE_LIB_73

#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>

class BrezenhamCircle {
public:
    BrezenhamCircle() = default;
    BrezenhamCircle(const BrezenhamCircle& arr) = default;
    BrezenhamCircle& operator=(const BrezenhamCircle& rhs) = default;
    ~BrezenhamCircle() = default;
    BrezenhamCircle(BrezenhamCircle&& other) noexcept = default;
    BrezenhamCircle& operator=(BrezenhamCircle&& other) = default;

    /**
   @brief ����������� � �����������.

   @param center ����� ����������.
   @param radius ������ ����������.
   @param color ���� ���������� � ������ BGR.
   */
    BrezenhamCircle(cv::Point& center, int radius, cv::Scalar& color);

    // ������� ������������ ���� ����������. ������ ���� � ���������� ������ �� ��������� ����������� ��������.
    std::vector<cv::Point> GetArc(cv::Mat& img, double startDegrees, double endDegrees, bool showDemo);

    void Demo();


private:
    cv::Point center = cv::Point(250, 250);
    int radius = 100;
    cv::Scalar color = cv::Scalar(255, 0, 0);

private:
    double toRadian(const double& degrees);
};

#endif