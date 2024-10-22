#ifndef _MAZE_FILE_SAVER_H_
#define _MAZE_FILE_SAVER_H_

#include <fstream>

#include "maze.h"

namespace s21 {

class MazeFileSaver : IMazeSaver {
 public:
  MazeFileSaver(const Maze &m, const std::string &path)
      : maze_(m), path_(path){};

  virtual void save() const override;

 private:
  const Maze &maze_;
  const std::string &path_;
};

}  // namespace s21

#endif