#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <sstream>
#include <limits>

class DataAnalyzer {
private:
    std::vector<double> data;

public:
    // 手动输入数据
    void inputData() {
        std::cout << "=== 数据输入模式 ===\n";
        std::cout << "请输入数据个数: ";
        int n;
        std::cin >> n;
        
        data.clear();
        std::cout << "请依次输入 " << n << " 个数据:\n";
        for (int i = 0; i < n; i++) {
            double value;
            std::cout << "数据 " << (i + 1) << ": ";
            std::cin >> value;
            data.push_back(value);
        }
        
        // 清除输入缓冲区
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // 从字符串输入数据（逗号或空格分隔）
    void inputFromString(const std::string& inputStr) {
        data.clear();
        std::istringstream iss(inputStr);
        double value;
        char delimiter;
        
        while (iss >> value) {
            data.push_back(value);
            // 尝试读取分隔符
            if (!(iss >> delimiter)) {
                break;
            }
        }
    }

    // 计算平均值
    double calculateMean() const {
        if (data.empty()) return 0.0;
        double sum = 0.0;
        for (double num : data) {
            sum += num;
        }
        return sum / data.size();
    }

    // 计算中位数
    double calculateMedian() {
        if (data.empty()) return 0.0;
        
        std::vector<double> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        size_t n = sortedData.size();
        
        if (n % 2 == 0) {
            return (sortedData[n/2 - 1] + sortedData[n/2]) / 2.0;
        } else {
            return sortedData[n/2];
        }
    }

    // 计算众数
    std::vector<double> calculateMode() const {
        if (data.empty()) return {};
        
        std::map<double, int> frequencyMap;
        int maxCount = 0;
        std::vector<double> modes;
        
        // 统计频率
        for (double num : data) {
            frequencyMap[num]++;
            if (frequencyMap[num] > maxCount) {
                maxCount = frequencyMap[num];
            }
        }
        
        // 收集所有出现次数等于maxCount的值
        for (const auto& pair : frequencyMap) {
            if (pair.second == maxCount) {
                modes.push_back(pair.first);
            }
        }
        
        return modes;
    }

    // 计算标准差
    double calculateStdDev() const {
        if (data.empty()) return 0.0;
        
        double mean = calculateMean();
        double sumSquaredDiff = 0.0;
        
        for (double num : data) {
            sumSquaredDiff += (num - mean) * (num - mean);
        }
        
        return std::sqrt(sumSquaredDiff / data.size());
    }

    // 计算方差
    double calculateVariance() const {
        if (data.empty()) return 0.0;
        double stdDev = calculateStdDev();
        return stdDev * stdDev;
    }

    // 计算最大值
    double calculateMax() const {
        if (data.empty()) return 0.0;
        return *std::max_element(data.begin(), data.end());
    }

    // 计算最小值
    double calculateMin() const {
        if (data.empty()) return 0.0;
        return *std::min_element(data.begin(), data.end());
    }

    // 计算极差
    double calculateRange() const {
        if (data.empty()) return 0.0;
        return calculateMax() - calculateMin();
    }

    // 显示数据
    void displayData() const {
        std::cout << "当前数据集 (" << data.size() << " 个): ";
        for (size_t i = 0; i < data.size(); i++) {
            std::cout << data[i];
            if (i < data.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }

    // 获取数据数量
    size_t getDataCount() const {
        return data.size();
    }
};

// 显示分析结果
void displayAnalysisResults(DataAnalyzer& analyzer) {
    std::cout << "\n=== 数据分析结果 ===\n";
    analyzer.displayData();
    std::cout << "数据个数: " << analyzer.getDataCount() << "\n";
    std::cout << "平均值: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateMean() << "\n";
    std::cout << "中位数: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateMedian() << "\n";
    
    std::vector<double> modes = analyzer.calculateMode();
    std::cout << "众数: ";
    if (modes.empty()) {
        std::cout << "无";
    } else {
        for (size_t i = 0; i < modes.size(); i++) {
            std::cout << modes[i];
            if (i < modes.size() - 1) std::cout << ", ";
        }
    }
    std::cout << "\n";
    
    std::cout << "标准差: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateStdDev() << "\n";
    std::cout << "方差: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateVariance() << "\n";
    std::cout << "最大值: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateMax() << "\n";
    std::cout << "最小值: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateMin() << "\n";
    std::cout << "极差: " << std::fixed << std::setprecision(4) 
              << analyzer.calculateRange() << "\n";
}

int main() {
    DataAnalyzer analyzer;
    int choice;
    
    std::cout << "=== 简易数据分析系统 ===\n";
    
    do {
        std::cout << "\n请选择操作:\n";
        std::cout << "1. 手动输入数据\n";
        std::cout << "2. 使用示例数据\n";
        std::cout << "3. 字符串输入数据\n";
        std::cout << "4. 显示分析结果\n";
        std::cout << "0. 退出\n";
        std::cout << "选择: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                analyzer.inputData();
                break;
            case 2:
                analyzer.inputFromString("1.2 2.3 2.3 3.4 4.5 4.5 4.5 5.6");
                std::cout << "已加载示例数据\n";
                analyzer.displayData();
                break;
            case 3:
                {
                    std::string inputStr;
                    std::cout << "请输入数据（用空格或逗号分隔）: ";
                    std::cin.ignore();
                    std::getline(std::cin, inputStr);
                    analyzer.inputFromString(inputStr);
                    std::cout << "数据加载完成\n";
                    analyzer.displayData();
                }
                break;
            case 4:
                if (analyzer.getDataCount() > 0) {
                    displayAnalysisResults(analyzer);
                } else {
                    std::cout << "请先输入数据！\n";
                }
                break;
            case 0:
                std::cout << "感谢使用！\n";
                break;
            default:
                std::cout << "无效选择，请重新输入！\n";
        }
    } while (choice != 0);
    
    return 0;
}
