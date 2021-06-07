#include "pch-c.h"
#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include "codegen/il2cpp-codegen-metadata.h"





// 0x00000001 System.Exception System.Linq.Error::ArgumentNull(System.String)
extern void Error_ArgumentNull_m0EDA0D46D72CA692518E3E2EB75B48044D8FD41E (void);
// 0x00000002 System.Exception System.Linq.Error::MoreThanOneMatch()
extern void Error_MoreThanOneMatch_m4C4756AF34A76EF12F3B2B6D8C78DE547F0FBCF8 (void);
// 0x00000003 System.Exception System.Linq.Error::NoElements()
extern void Error_NoElements_mB89E91246572F009281D79730950808F17C3F353 (void);
// 0x00000004 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Where(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000005 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
// 0x00000006 System.Func`2<TSource,System.Boolean> System.Linq.Enumerable::CombinePredicates(System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,System.Boolean>)
// 0x00000007 System.Func`2<TSource,TResult> System.Linq.Enumerable::CombineSelectors(System.Func`2<TSource,TMiddle>,System.Func`2<TMiddle,TResult>)
// 0x00000008 TSource[] System.Linq.Enumerable::ToArray(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000009 System.Collections.Generic.List`1<TSource> System.Linq.Enumerable::ToList(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000000A TSource System.Linq.Enumerable::First(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000000B TSource System.Linq.Enumerable::SingleOrDefault(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000000C System.Boolean System.Linq.Enumerable::Any(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000000D System.Boolean System.Linq.Enumerable::Any(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000000E System.Int32 System.Linq.Enumerable::Count(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000000F System.Void System.Linq.Enumerable/Iterator`1::.ctor()
// 0x00000010 TSource System.Linq.Enumerable/Iterator`1::get_Current()
// 0x00000011 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/Iterator`1::Clone()
// 0x00000012 System.Void System.Linq.Enumerable/Iterator`1::Dispose()
// 0x00000013 System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/Iterator`1::GetEnumerator()
// 0x00000014 System.Boolean System.Linq.Enumerable/Iterator`1::MoveNext()
// 0x00000015 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/Iterator`1::Select(System.Func`2<TSource,TResult>)
// 0x00000016 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/Iterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x00000017 System.Object System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerator.get_Current()
// 0x00000018 System.Collections.IEnumerator System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000019 System.Void System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerator.Reset()
// 0x0000001A System.Void System.Linq.Enumerable/WhereEnumerableIterator`1::.ctor(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000001B System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereEnumerableIterator`1::Clone()
// 0x0000001C System.Void System.Linq.Enumerable/WhereEnumerableIterator`1::Dispose()
// 0x0000001D System.Boolean System.Linq.Enumerable/WhereEnumerableIterator`1::MoveNext()
// 0x0000001E System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereEnumerableIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x0000001F System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereEnumerableIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x00000020 System.Void System.Linq.Enumerable/WhereArrayIterator`1::.ctor(TSource[],System.Func`2<TSource,System.Boolean>)
// 0x00000021 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereArrayIterator`1::Clone()
// 0x00000022 System.Boolean System.Linq.Enumerable/WhereArrayIterator`1::MoveNext()
// 0x00000023 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereArrayIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x00000024 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereArrayIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x00000025 System.Void System.Linq.Enumerable/WhereListIterator`1::.ctor(System.Collections.Generic.List`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000026 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereListIterator`1::Clone()
// 0x00000027 System.Boolean System.Linq.Enumerable/WhereListIterator`1::MoveNext()
// 0x00000028 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereListIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x00000029 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereListIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x0000002A System.Void System.Linq.Enumerable/WhereSelectEnumerableIterator`2::.ctor(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x0000002B System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Clone()
// 0x0000002C System.Void System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Dispose()
// 0x0000002D System.Boolean System.Linq.Enumerable/WhereSelectEnumerableIterator`2::MoveNext()
// 0x0000002E System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x0000002F System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x00000030 System.Void System.Linq.Enumerable/WhereSelectArrayIterator`2::.ctor(TSource[],System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x00000031 System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectArrayIterator`2::Clone()
// 0x00000032 System.Boolean System.Linq.Enumerable/WhereSelectArrayIterator`2::MoveNext()
// 0x00000033 System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectArrayIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x00000034 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectArrayIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x00000035 System.Void System.Linq.Enumerable/WhereSelectListIterator`2::.ctor(System.Collections.Generic.List`1<TSource>,System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x00000036 System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectListIterator`2::Clone()
// 0x00000037 System.Boolean System.Linq.Enumerable/WhereSelectListIterator`2::MoveNext()
// 0x00000038 System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectListIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x00000039 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectListIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x0000003A System.Void System.Linq.Enumerable/<>c__DisplayClass6_0`1::.ctor()
// 0x0000003B System.Boolean System.Linq.Enumerable/<>c__DisplayClass6_0`1::<CombinePredicates>b__0(TSource)
// 0x0000003C System.Void System.Linq.Enumerable/<>c__DisplayClass7_0`3::.ctor()
// 0x0000003D TResult System.Linq.Enumerable/<>c__DisplayClass7_0`3::<CombineSelectors>b__0(TSource)
// 0x0000003E System.Void System.Linq.Buffer`1::.ctor(System.Collections.Generic.IEnumerable`1<TElement>)
// 0x0000003F TElement[] System.Linq.Buffer`1::ToArray()
// 0x00000040 System.Void System.Collections.Generic.HashSet`1::.ctor()
// 0x00000041 System.Void System.Collections.Generic.HashSet`1::.ctor(System.Collections.Generic.IEqualityComparer`1<T>)
// 0x00000042 System.Void System.Collections.Generic.HashSet`1::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
// 0x00000043 System.Void System.Collections.Generic.HashSet`1::System.Collections.Generic.ICollection<T>.Add(T)
// 0x00000044 System.Void System.Collections.Generic.HashSet`1::Clear()
// 0x00000045 System.Boolean System.Collections.Generic.HashSet`1::Contains(T)
// 0x00000046 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[],System.Int32)
// 0x00000047 System.Boolean System.Collections.Generic.HashSet`1::Remove(T)
// 0x00000048 System.Int32 System.Collections.Generic.HashSet`1::get_Count()
// 0x00000049 System.Boolean System.Collections.Generic.HashSet`1::System.Collections.Generic.ICollection<T>.get_IsReadOnly()
// 0x0000004A System.Collections.Generic.HashSet`1/Enumerator<T> System.Collections.Generic.HashSet`1::GetEnumerator()
// 0x0000004B System.Collections.Generic.IEnumerator`1<T> System.Collections.Generic.HashSet`1::System.Collections.Generic.IEnumerable<T>.GetEnumerator()
// 0x0000004C System.Collections.IEnumerator System.Collections.Generic.HashSet`1::System.Collections.IEnumerable.GetEnumerator()
// 0x0000004D System.Void System.Collections.Generic.HashSet`1::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
// 0x0000004E System.Void System.Collections.Generic.HashSet`1::OnDeserialization(System.Object)
// 0x0000004F System.Boolean System.Collections.Generic.HashSet`1::Add(T)
// 0x00000050 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[])
// 0x00000051 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[],System.Int32,System.Int32)
// 0x00000052 System.Void System.Collections.Generic.HashSet`1::Initialize(System.Int32)
// 0x00000053 System.Void System.Collections.Generic.HashSet`1::IncreaseCapacity()
// 0x00000054 System.Void System.Collections.Generic.HashSet`1::SetCapacity(System.Int32)
// 0x00000055 System.Boolean System.Collections.Generic.HashSet`1::AddIfNotPresent(T)
// 0x00000056 System.Int32 System.Collections.Generic.HashSet`1::InternalGetHashCode(T)
// 0x00000057 System.Void System.Collections.Generic.HashSet`1/Enumerator::.ctor(System.Collections.Generic.HashSet`1<T>)
// 0x00000058 System.Void System.Collections.Generic.HashSet`1/Enumerator::Dispose()
// 0x00000059 System.Boolean System.Collections.Generic.HashSet`1/Enumerator::MoveNext()
// 0x0000005A T System.Collections.Generic.HashSet`1/Enumerator::get_Current()
// 0x0000005B System.Object System.Collections.Generic.HashSet`1/Enumerator::System.Collections.IEnumerator.get_Current()
// 0x0000005C System.Void System.Collections.Generic.HashSet`1/Enumerator::System.Collections.IEnumerator.Reset()
static Il2CppMethodPointer s_methodPointers[92] = 
{
	Error_ArgumentNull_m0EDA0D46D72CA692518E3E2EB75B48044D8FD41E,
	Error_MoreThanOneMatch_m4C4756AF34A76EF12F3B2B6D8C78DE547F0FBCF8,
	Error_NoElements_mB89E91246572F009281D79730950808F17C3F353,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};
static const int32_t s_InvokerIndices[92] = 
{
	1959,
	2040,
	2040,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
};
static const Il2CppTokenRangePair s_rgctxIndices[29] = 
{
	{ 0x02000004, { 48, 4 } },
	{ 0x02000005, { 52, 9 } },
	{ 0x02000006, { 63, 7 } },
	{ 0x02000007, { 72, 10 } },
	{ 0x02000008, { 84, 11 } },
	{ 0x02000009, { 98, 9 } },
	{ 0x0200000A, { 110, 12 } },
	{ 0x0200000B, { 125, 1 } },
	{ 0x0200000C, { 126, 2 } },
	{ 0x0200000D, { 128, 4 } },
	{ 0x0200000E, { 132, 21 } },
	{ 0x02000010, { 153, 2 } },
	{ 0x06000004, { 0, 10 } },
	{ 0x06000005, { 10, 10 } },
	{ 0x06000006, { 20, 5 } },
	{ 0x06000007, { 25, 5 } },
	{ 0x06000008, { 30, 3 } },
	{ 0x06000009, { 33, 2 } },
	{ 0x0600000A, { 35, 4 } },
	{ 0x0600000B, { 39, 3 } },
	{ 0x0600000C, { 42, 1 } },
	{ 0x0600000D, { 43, 3 } },
	{ 0x0600000E, { 46, 2 } },
	{ 0x0600001E, { 61, 2 } },
	{ 0x06000023, { 70, 2 } },
	{ 0x06000028, { 82, 2 } },
	{ 0x0600002E, { 95, 3 } },
	{ 0x06000033, { 107, 3 } },
	{ 0x06000038, { 122, 3 } },
};
static const Il2CppRGCTXDefinition s_rgctxValues[155] = 
{
	{ (Il2CppRGCTXDataType)2, 1021 },
	{ (Il2CppRGCTXDataType)3, 3125 },
	{ (Il2CppRGCTXDataType)2, 1694 },
	{ (Il2CppRGCTXDataType)2, 1403 },
	{ (Il2CppRGCTXDataType)3, 5536 },
	{ (Il2CppRGCTXDataType)2, 1074 },
	{ (Il2CppRGCTXDataType)2, 1410 },
	{ (Il2CppRGCTXDataType)3, 5559 },
	{ (Il2CppRGCTXDataType)2, 1405 },
	{ (Il2CppRGCTXDataType)3, 5543 },
	{ (Il2CppRGCTXDataType)2, 1022 },
	{ (Il2CppRGCTXDataType)3, 3126 },
	{ (Il2CppRGCTXDataType)2, 1705 },
	{ (Il2CppRGCTXDataType)2, 1412 },
	{ (Il2CppRGCTXDataType)3, 5566 },
	{ (Il2CppRGCTXDataType)2, 1088 },
	{ (Il2CppRGCTXDataType)2, 1420 },
	{ (Il2CppRGCTXDataType)3, 5594 },
	{ (Il2CppRGCTXDataType)2, 1416 },
	{ (Il2CppRGCTXDataType)3, 5579 },
	{ (Il2CppRGCTXDataType)2, 374 },
	{ (Il2CppRGCTXDataType)3, 14 },
	{ (Il2CppRGCTXDataType)3, 15 },
	{ (Il2CppRGCTXDataType)2, 651 },
	{ (Il2CppRGCTXDataType)3, 2300 },
	{ (Il2CppRGCTXDataType)2, 375 },
	{ (Il2CppRGCTXDataType)3, 20 },
	{ (Il2CppRGCTXDataType)3, 21 },
	{ (Il2CppRGCTXDataType)2, 655 },
	{ (Il2CppRGCTXDataType)3, 2302 },
	{ (Il2CppRGCTXDataType)2, 424 },
	{ (Il2CppRGCTXDataType)3, 422 },
	{ (Il2CppRGCTXDataType)3, 423 },
	{ (Il2CppRGCTXDataType)2, 1075 },
	{ (Il2CppRGCTXDataType)3, 3406 },
	{ (Il2CppRGCTXDataType)2, 970 },
	{ (Il2CppRGCTXDataType)2, 722 },
	{ (Il2CppRGCTXDataType)2, 793 },
	{ (Il2CppRGCTXDataType)2, 846 },
	{ (Il2CppRGCTXDataType)2, 794 },
	{ (Il2CppRGCTXDataType)2, 847 },
	{ (Il2CppRGCTXDataType)3, 2301 },
	{ (Il2CppRGCTXDataType)2, 788 },
	{ (Il2CppRGCTXDataType)2, 789 },
	{ (Il2CppRGCTXDataType)2, 845 },
	{ (Il2CppRGCTXDataType)3, 2299 },
	{ (Il2CppRGCTXDataType)2, 721 },
	{ (Il2CppRGCTXDataType)2, 792 },
	{ (Il2CppRGCTXDataType)3, 3127 },
	{ (Il2CppRGCTXDataType)3, 3129 },
	{ (Il2CppRGCTXDataType)2, 262 },
	{ (Il2CppRGCTXDataType)3, 3128 },
	{ (Il2CppRGCTXDataType)3, 3137 },
	{ (Il2CppRGCTXDataType)2, 1025 },
	{ (Il2CppRGCTXDataType)2, 1406 },
	{ (Il2CppRGCTXDataType)3, 5544 },
	{ (Il2CppRGCTXDataType)3, 3138 },
	{ (Il2CppRGCTXDataType)2, 820 },
	{ (Il2CppRGCTXDataType)2, 863 },
	{ (Il2CppRGCTXDataType)3, 2307 },
	{ (Il2CppRGCTXDataType)3, 6633 },
	{ (Il2CppRGCTXDataType)2, 1417 },
	{ (Il2CppRGCTXDataType)3, 5580 },
	{ (Il2CppRGCTXDataType)3, 3130 },
	{ (Il2CppRGCTXDataType)2, 1024 },
	{ (Il2CppRGCTXDataType)2, 1404 },
	{ (Il2CppRGCTXDataType)3, 5537 },
	{ (Il2CppRGCTXDataType)3, 2306 },
	{ (Il2CppRGCTXDataType)3, 3131 },
	{ (Il2CppRGCTXDataType)3, 6632 },
	{ (Il2CppRGCTXDataType)2, 1413 },
	{ (Il2CppRGCTXDataType)3, 5567 },
	{ (Il2CppRGCTXDataType)3, 3144 },
	{ (Il2CppRGCTXDataType)2, 1026 },
	{ (Il2CppRGCTXDataType)2, 1411 },
	{ (Il2CppRGCTXDataType)3, 5560 },
	{ (Il2CppRGCTXDataType)3, 3441 },
	{ (Il2CppRGCTXDataType)3, 1625 },
	{ (Il2CppRGCTXDataType)3, 2308 },
	{ (Il2CppRGCTXDataType)3, 1624 },
	{ (Il2CppRGCTXDataType)3, 3145 },
	{ (Il2CppRGCTXDataType)3, 6634 },
	{ (Il2CppRGCTXDataType)2, 1421 },
	{ (Il2CppRGCTXDataType)3, 5595 },
	{ (Il2CppRGCTXDataType)3, 3158 },
	{ (Il2CppRGCTXDataType)2, 1028 },
	{ (Il2CppRGCTXDataType)2, 1419 },
	{ (Il2CppRGCTXDataType)3, 5582 },
	{ (Il2CppRGCTXDataType)3, 3159 },
	{ (Il2CppRGCTXDataType)2, 823 },
	{ (Il2CppRGCTXDataType)2, 866 },
	{ (Il2CppRGCTXDataType)3, 2312 },
	{ (Il2CppRGCTXDataType)3, 2311 },
	{ (Il2CppRGCTXDataType)2, 1408 },
	{ (Il2CppRGCTXDataType)3, 5546 },
	{ (Il2CppRGCTXDataType)3, 6638 },
	{ (Il2CppRGCTXDataType)2, 1418 },
	{ (Il2CppRGCTXDataType)3, 5581 },
	{ (Il2CppRGCTXDataType)3, 3151 },
	{ (Il2CppRGCTXDataType)2, 1027 },
	{ (Il2CppRGCTXDataType)2, 1415 },
	{ (Il2CppRGCTXDataType)3, 5569 },
	{ (Il2CppRGCTXDataType)3, 2310 },
	{ (Il2CppRGCTXDataType)3, 2309 },
	{ (Il2CppRGCTXDataType)3, 3152 },
	{ (Il2CppRGCTXDataType)2, 1407 },
	{ (Il2CppRGCTXDataType)3, 5545 },
	{ (Il2CppRGCTXDataType)3, 6637 },
	{ (Il2CppRGCTXDataType)2, 1414 },
	{ (Il2CppRGCTXDataType)3, 5568 },
	{ (Il2CppRGCTXDataType)3, 3165 },
	{ (Il2CppRGCTXDataType)2, 1029 },
	{ (Il2CppRGCTXDataType)2, 1423 },
	{ (Il2CppRGCTXDataType)3, 5597 },
	{ (Il2CppRGCTXDataType)3, 3442 },
	{ (Il2CppRGCTXDataType)3, 1627 },
	{ (Il2CppRGCTXDataType)3, 2314 },
	{ (Il2CppRGCTXDataType)3, 2313 },
	{ (Il2CppRGCTXDataType)3, 1626 },
	{ (Il2CppRGCTXDataType)3, 3166 },
	{ (Il2CppRGCTXDataType)2, 1409 },
	{ (Il2CppRGCTXDataType)3, 5547 },
	{ (Il2CppRGCTXDataType)3, 6639 },
	{ (Il2CppRGCTXDataType)2, 1422 },
	{ (Il2CppRGCTXDataType)3, 5596 },
	{ (Il2CppRGCTXDataType)3, 2304 },
	{ (Il2CppRGCTXDataType)3, 2305 },
	{ (Il2CppRGCTXDataType)3, 2315 },
	{ (Il2CppRGCTXDataType)2, 723 },
	{ (Il2CppRGCTXDataType)2, 1708 },
	{ (Il2CppRGCTXDataType)2, 804 },
	{ (Il2CppRGCTXDataType)2, 848 },
	{ (Il2CppRGCTXDataType)3, 1997 },
	{ (Il2CppRGCTXDataType)2, 586 },
	{ (Il2CppRGCTXDataType)3, 2494 },
	{ (Il2CppRGCTXDataType)3, 2495 },
	{ (Il2CppRGCTXDataType)3, 2500 },
	{ (Il2CppRGCTXDataType)2, 897 },
	{ (Il2CppRGCTXDataType)3, 2497 },
	{ (Il2CppRGCTXDataType)3, 6837 },
	{ (Il2CppRGCTXDataType)2, 567 },
	{ (Il2CppRGCTXDataType)3, 1620 },
	{ (Il2CppRGCTXDataType)1, 778 },
	{ (Il2CppRGCTXDataType)2, 1714 },
	{ (Il2CppRGCTXDataType)3, 2496 },
	{ (Il2CppRGCTXDataType)1, 1714 },
	{ (Il2CppRGCTXDataType)1, 897 },
	{ (Il2CppRGCTXDataType)2, 1752 },
	{ (Il2CppRGCTXDataType)2, 1714 },
	{ (Il2CppRGCTXDataType)3, 2501 },
	{ (Il2CppRGCTXDataType)3, 2499 },
	{ (Il2CppRGCTXDataType)3, 2498 },
	{ (Il2CppRGCTXDataType)2, 181 },
	{ (Il2CppRGCTXDataType)3, 1628 },
	{ (Il2CppRGCTXDataType)2, 271 },
};
extern const CustomAttributesCacheGenerator g_System_Core_AttributeGenerators[];
IL2CPP_EXTERN_C const Il2CppCodeGenModule g_System_Core_CodeGenModule;
const Il2CppCodeGenModule g_System_Core_CodeGenModule = 
{
	"System.Core.dll",
	92,
	s_methodPointers,
	0,
	NULL,
	s_InvokerIndices,
	0,
	NULL,
	29,
	s_rgctxIndices,
	155,
	s_rgctxValues,
	NULL,
	g_System_Core_AttributeGenerators,
	NULL, // module initializer,
	NULL,
	NULL,
	NULL,
};
