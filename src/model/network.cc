//#include <chrono>
#include "network.h"
//#include "data.h"
//#include "reader.h"

namespace s21 {

    auto Network::test_net(const std::string& fileName,
                                   const double datasetUsage) -> Metrics {
        Reader reader;
        Metrics metrics;
        reader.open_file(fileName);
        const int fileSize = reader.get_file_size();

        int dataSize = static_cast<int>(fileSize * datasetUsage);
        int tp = 0, fp = 0, tn = 0, fn = 0;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < dataSize; i++) {
            s21::Data data = reader.get_data();
            if (reader.is_open()) {
                this->feed_init_value(data.m_input_);
                this->feed_forward();
                std::vector<double> res = this->get_result_vector();
                int answer = this->get_result();
                if (data.m_result_ == answer + 1) metrics.set_accuracy(1);
                for (int j = 0; j < 26; j++) {
                    if (j == answer) {
                        if (res[j] > 0.5)
                            tp++;
                        else
                            fp++;
                    } else {
                        if (res[j] > 0.5)
                            fn++;
                        else
                            tn++;
                    }
                }
            }
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
                std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        metrics.set_ed_time(duration.count());

        metrics.Calculate(tp, fp, tn, fn, dataSize);
        reader.close_file();
        return metrics;
    }



    auto Network::train_network(const std::string& fileName, const size_t epochs)
    -> std::vector<double> {
        Reader reader;
        std::vector<double> errors;
        for (size_t i = 0; i < epochs; i++) {
            int accuracy = 0;
            reader.open_file(fileName);
            const int dataSize = reader.get_file_size();
            for (int j = 0; j < dataSize; j++) {
                std::vector<double> expected_vals(m_topology_.back());
                s21::Data data = reader.get_data();
                expected_vals[data.m_result_ - 1] = 1;
                this->feed_init_value(data.m_input_);
                this->feed_forward();
                if (static_cast<size_t>(data.m_result_ - 1) == this->get_result()) {
                    accuracy++;
                }
                this->back_propagation(expected_vals);
            }
            accuracy =
                    (static_cast<double>(accuracy) / static_cast<double>(dataSize)) * 100.0;
            errors.push_back(100.0 - accuracy);
        }
        reader.close_file();

        return errors;
    }



    auto Network::cross_validation(const std::string &fileName,
                                           const size_t k) -> std::vector<double> {
        Reader reader;
        reader.open_file(fileName);
        const int fileSize = reader.get_file_size();

        std::vector<s21::Data> testDataInput;
        std::vector<double> accuracyVals;

        std::vector<double> expectedVals(this->m_topology_.back());
        s21::Data data;

        int testDataSize = fileSize / k;
        /* индексы строки, обозначающие начало и конец данных для теста*/
        int getTest = 0, endTest = testDataSize;
        for (int i = 0; i < k; i++) {
            int accuracy = 0;
            for (int iterator = 0; iterator < fileSize; iterator++) {
                if (iterator >= getTest && iterator < endTest) {
                    /// сбор данных для теста
                    testDataInput.push_back(reader.get_data());
                } else {
                    /// обучение
                    data = reader.get_data();
                    expectedVals[data.m_result_ - 1] = 1;
                    this->feed_init_value(data.m_input_);
                    this->feed_forward();
                    this->back_propagation(expectedVals);
                    expectedVals[data.m_result_ - 1] = 0;
                }
            }
            /// тест
            for (int j = 0; j < testDataInput.size(); j++) {
                this->feed_init_value(testDataInput[j].m_input_);
                this->feed_forward();
                if (this->get_result() == testDataInput[j].m_result_ - 1) accuracy++;
            }

            getTest += testDataSize;
            endTest += testDataSize;

            testDataInput.clear();
            accuracyVals.push_back(static_cast<double>(accuracy) / testDataSize * 100);
            if (i != k - 1) reader.open_file(fileName);
        }

        reader.close_file();
        return accuracyVals;
    }

}
