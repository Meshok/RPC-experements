#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace rps {

class User {
 private:
  User(uint32_t user_id, const std::string& user_name)
      : user_id_(user_id), user_name_(user_name) {}

 public:
  User(const User& other) = default;
  User(User&& other) = default;
  User& operator=(const User& other) = default;
  User& operator=(User&& other) = default;

  static User make_user(const std::string& user_name) {
    return User(++last_user_id_, user_name);
  }

 public:
  auto GetUserId() const { return user_id_; }
  auto GetUserName() const { return std::string_view(user_name_); }

 private:
  inline static uint32_t last_user_id_ = 0;

 private:
  const uint32_t user_id_ = 0;
  const std::string user_name_ = "";
};

}  // namespace rps
