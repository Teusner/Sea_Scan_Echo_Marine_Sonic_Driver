#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace SeaScanEcho {
   class Reply {
      public:
         // Constructor
         Reply(std::string sentence);

         // Check if the message is valid
         bool Valid() const;

         // Get fields from NMEA msg
         std::vector<std::string> Fields() const;

      private:
         // Private sentence storage
         std::string s_;

         // Fields
         std::vector<std::string> fields_;

         // Checksum verification
         bool _checksum() const;
   };
} // namespace SeaScanEcho