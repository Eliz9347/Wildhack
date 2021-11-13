#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void
SaveVector(const std::vector<std::string> source,
           std::string& filename,
           char delimiter)
{
  std::ofstream output;
  output.open(filename);
  for (int i = 0; i < source.size(); ++i) {
    output << i << delimiter << source[i] << std::endl;
  }
}

std::string
GetWeekDay(const int day)
{
  switch (day) {
    case 0:
      return "Monday";
    case 1:
      return "Tuesday";
    case 2:
      return "Wednesday";
    case 3:
      return "Thursday";
    case 4:
      return "Friday";
    case 5:
      return "Saturday";
    case 6:
      return "Sunday";
    default:
      throw std::invalid_argument("invalid day of the week");
  }
}

int
main(int argc, char* argv[])
{

  if (argc < 3) {
    std::cout << "USAGE: \"full_filepath "
                 "lines_per_file\"\nC:/WildHack/py/df.csv 8000000"
              << std::endl;
    return 0;
  }

  const std::string sourcepath = argv[1];
  // const char delimiter = argv[2][0];
  const int lines_n = atoi(argv[2]);

  std::ifstream source(sourcepath);
  std::string line;
  //  std::vector<std::string> users;
  /*std::string week_day = "0";
  int week_index = 0;*/
  int file_number = 0;
  std::ofstream output;
  std::string filename = "result_" + std::to_string(file_number) + ".csv";
  output.open(filename);
  std::string first_line;

  int i = 0;
  while (std::getline(source, line)) {
    if (i == 0) {
      if (first_line.empty())
        first_line = line;
      else
        output << first_line << std::endl;
    }

    /*std::stringstream ss(line);
    ss.str(line);
    std::string val;*/
    output << line << std::endl;
    i++;

    if (lines_n < i) {
      i = 0;
      output.close();
      ++file_number;
      filename = "result_" + std::to_string(file_number) + ".csv";
      output.open(filename);
    }
    //  while (std::getline(ss, val, delimiter)) {
    //    if (i != 0) {
    //      output << delimiter;
    //    }

    //    /*if (i == 1) {
    //     auto user_it = std::find(users.begin(), users.end(), val);
    //     if (user_it == users.end()) {
    //       output << std::to_string(users.size());
    //       users.push_back(val);
    //     } else {
    //       output << std::to_string(user_it - users.begin());
    //     }
    //   }*/

    //    if (i == 5 && val != week_day && val != "weekday") {
    //      std::string filename_vec = "resultVector_" +
    //                                 GetWeekDay(std::stoi(week_day)) +
    //                                 std::to_string(week_index) + ".txt";
    //      // SaveVector(users, filename_vec, delimiter);
    //      // users.clear();
    //      output.close();
    //      week_day = val;
    //      if (val == "0")
    //        week_index++;

    //      filename = "result_" + GetWeekDay(std::stoi(week_day)) +
    //                 std::to_string(week_index) + ".csv";
    //      output.open(filename);
    //      output << val;
    //    }

    //    else
    //      output << val;
    //    i++;
    //  }
    //  output << std::endl;
  }
  output.close();
  /*std::string filename_vec = "resultVector_" + GetWeekDay(std::stoi(week_day))
  + std::to_string(week_index) + ".txt"; SaveVector(users, filename_vec,
  delimiter);*/
  return 0;
}