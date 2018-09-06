#pragma once
#include "ConnectKafkaInterface.h"
#include "TopicMetadataStruct.h"
#include <CLI/CLI.hpp>
#include <iostream>
#include <librdkafka/rdkafkacpp.h>

class ConnectKafkaFake : public ConnectKafkaInterface {
public:
  ConnectKafkaFake();

  std::string getAllTopics() override;

  std::pair<std::string, bool> consumeFromOffset() override;

  std::pair<std::string, bool> consumeLastNMessages() override;

  std::vector<OffsetsStruct> getHighAndLowOffsets(std::string Topic) override;

  int64_t getNumberOfTopicPartitions(std::string TopicName) override;

  void subscribeAtOffset(int64_t Offset, std::string TopicName) override;

  void subscribeToLastNMessages(int64_t NMessages,
                                std::string TopicName) override;
};