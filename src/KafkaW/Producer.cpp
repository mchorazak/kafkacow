#include "Producer.h"
#include "KafkaConfig.h"
#include <memory>

Producer::Producer(std::string Broker) {
  std::string ErrStr;
  this->KafkaProducer =
      std::shared_ptr<RdKafka::Producer>(RdKafka::Producer::create(
          createGlobalConfiguration(Broker).get(), ErrStr));
  if (!ErrStr.empty()) {
    ErrStr.append(
        "Error creating KafkaProducer in KafkaW::Producer::Producer.");
    Logger->error(ErrStr);
  }
}

void Producer::produce() {}
