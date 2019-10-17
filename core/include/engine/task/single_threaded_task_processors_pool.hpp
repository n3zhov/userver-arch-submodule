#pragma once

#include <memory>
#include <vector>

namespace engine {

struct TaskProcessorConfig;
class TaskProcessor;

class SingleThreadedTaskProcessorsPool final {
 public:
  // Do NOT use directly! Use componenets::SingleThreadedTaskProcessors or for
  // tests use utest::MakeSingleThreadedTaskProcessorsPool()
  explicit SingleThreadedTaskProcessorsPool(
      const engine::TaskProcessorConfig& config_base);
  ~SingleThreadedTaskProcessorsPool();

  size_t GetSize() const noexcept { return processors_.size(); }
  engine::TaskProcessor& At(size_t idx) { return *processors_.at(idx); }

 private:
  std::vector<std::unique_ptr<engine::TaskProcessor>> processors_;
};

}  // namespace engine