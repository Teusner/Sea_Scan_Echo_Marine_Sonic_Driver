#pragma once

#include <string>
#include <string_view>
#include <vector>

class Reply {
   public:
      // Constructor
      Reply(std::string_view sentence);

      // Check if the message is valid
      bool Valid() const;

      // Get fields from NMEA msg
      std::vector<std::string_view> Fields() const;

   private:
      // Private sentence storage
      std::string_view s_;

      // Fields
      std::vector<std::string_view> fields_;

      // Checksum verification
      bool _checksum() const;
};