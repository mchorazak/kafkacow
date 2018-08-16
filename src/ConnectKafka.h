#pragma once

#include "../test/ConnectKafkaParentClass.h"
#include <CLI/CLI.hpp>
#include <iostream>
#include <librdkafka/rdkafkacpp.h>

class ConnectKafka : public ConnectKafkaParentClass {
  std::shared_ptr<RdKafka::KafkaConsumer> Consumer;
  std::unique_ptr<RdKafka::Metadata> MetadataPointer;

public:
  std::shared_ptr<RdKafka::KafkaConsumer> GetConsumer() override;
  ConnectKafka(std::string Broker, std::string ErrStr);
  std::unique_ptr<RdKafka::Metadata> queryMetadata() override;
  std::string GetAllTopics() override;
};
