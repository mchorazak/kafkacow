#pragma once

#include "KafkaMessageMetadataStruct.h"
#include <flatbuffers/idl.h>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

class FlatbuffersTranslator {
public:
  FlatbuffersTranslator() { Logger = spdlog::get("LOG"); }

  std::string deserializeToYAML(KafkaMessageMetadataStruct MessageData,
                                std::string &FileID);

  std::pair<bool, std::string> getSchemaPathForID(const std::string &FileID);

  std::unique_ptr<flatbuffers::Parser> createParser(const std::string &FullName,
                                                    const std::string &Message,
                                                    const std::string &Schema);

private:
  // for each FILEID store path to schema file and schema itself
  std::map<std::string, std::pair<std::string, std::string>> FileIDMap;
  std::string FullPath = "schemas/";
  std::shared_ptr<spdlog::logger> Logger;
};
