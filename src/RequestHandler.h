#pragma once

#include "FlatbuffersTranslator.h"
#include "RequestHandlerInterface.h"
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <yaml-cpp/node/node.h>

class RequestHandler : public RequestHandlerInterface {
private:
  std::unique_ptr<ConnectKafkaInterface> KafkaConnection;
  void consumePartitions(KafkaMessageMetadataStruct &MessageData,
                         int &EOFPartitionCounter,
                         FlatbuffersTranslator &FlatBuffers);
  std::shared_ptr<spdlog::logger> Logger;
  UserArgumentStruct UserArguments;

public:
  explicit RequestHandler(
      std::unique_ptr<ConnectKafkaInterface> KafkaConnection,
      UserArgumentStruct &UserArguments)
      : KafkaConnection(std::move(KafkaConnection)) {
    Logger = spdlog::get("LOG");
    this->UserArguments = UserArguments;
  }

  void checkAndRun() override;

  void checkConsumerModeArguments(UserArgumentStruct UserArguments) override;

  void checkMetadataModeArguments(UserArgumentStruct UserArguments) override;

  void showTopicPartitionOffsets(UserArgumentStruct UserArguments) override;

  void subscribeConsumeAtOffset(std::string TopicName, int64_t Offset) override;
  void subscribeConsumeNLastMessages(std::string TopicName,
                                     int64_t NumberOfMessages,
                                     int Partition) override;

  void printMessage(const std::string &JSONMessage,
                    KafkaMessageMetadataStruct MessageData);
  void printMessage1(const std::string &JSONMessage,
                     KafkaMessageMetadataStruct MessageData);

  void recursivePrintJSONMap(YAML::Node &Node,
                             std::vector<std::vector<std::string>> &Keys);
  void recursivePrintJSONSequence(YAML::Node &Node,
                                  std::vector<std::vector<std::string>> &Keys);

  void printTruncatedMessage(const std::string &JSONMessage,
                             KafkaMessageMetadataStruct MessageData);
};
