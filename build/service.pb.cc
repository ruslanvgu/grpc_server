// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: service.proto

#include "service.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = ::PROTOBUF_NAMESPACE_ID::internal;
namespace package {
template <typename>
PROTOBUF_CONSTEXPR Empty::Empty(
    ::_pbi::ConstantInitialized) {}
struct EmptyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR EmptyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~EmptyDefaultTypeInternal() {}
  union {
    Empty _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 EmptyDefaultTypeInternal _Empty_default_instance_;
}  // namespace package
static ::_pb::Metadata file_level_metadata_service_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_service_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_service_2eproto = nullptr;
const ::uint32_t TableStruct_service_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::package::Empty, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::package::Empty)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::package::_Empty_default_instance_._instance,
};
const char descriptor_table_protodef_service_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\rservice.proto\022\007package\"\007\n\005Empty2A\n\020Kee"
    "pAliveService\022-\n\tKeepAlive\022\016.package.Emp"
    "ty\032\016.package.Empty\"\000b\006proto3"
};
static ::absl::once_flag descriptor_table_service_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_service_2eproto = {
    false,
    false,
    108,
    descriptor_table_protodef_service_2eproto,
    "service.proto",
    &descriptor_table_service_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_service_2eproto::offsets,
    file_level_metadata_service_2eproto,
    file_level_enum_descriptors_service_2eproto,
    file_level_service_descriptors_service_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_service_2eproto_getter() {
  return &descriptor_table_service_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_service_2eproto(&descriptor_table_service_2eproto);
namespace package {
// ===================================================================

class Empty::_Internal {
 public:
};

Empty::Empty(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena) {
  // @@protoc_insertion_point(arena_constructor:package.Empty)
}
Empty::Empty(const Empty& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  Empty* const _this = this; (void)_this;
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:package.Empty)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Empty::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Empty::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata Empty::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_service_2eproto_getter, &descriptor_table_service_2eproto_once,
      file_level_metadata_service_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace package
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::package::Empty*
Arena::CreateMaybeMessage< ::package::Empty >(Arena* arena) {
  return Arena::CreateMessageInternal< ::package::Empty >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"