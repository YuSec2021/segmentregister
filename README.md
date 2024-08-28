# Segment Register Translate

<p align="center">
    <a href="https://shields.io/community#language" alt="Backers on Open Collective">
        <img src="https://img.shields.io/badge/language-c++-brightgreen" /></a>
    <a href="https://github.com/yusec2021/segmentregister/pulse" alt="Activity">
        <img src="https://img.shields.io/github/commit-activity/m/yusec2021/segmentregister" /></a>
</p>

## :nut_and_bolt:Function

- `get*S`: read segment selector.
- `analysisSegmentSelector`: analysis Selector
- `analysisSegmentDescriptor`: analysis Descriptor, in function, analysis the Limit and BaseAddress.
- `analysisSegmentDescriptorOthers`: analysis Descriptor, in function, analysis the others properties.
- `checkSegmentType`: check Code Segment or Data Segment, check access rights.

## :black_nib:Usage

`use x86 compile because of the inline assembly`

if use x64 to compile, will tips:

**Using a non-standard extension: The use of the "__asm" keyword**



