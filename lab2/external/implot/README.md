# ImPlot
ImPlot is an immediate mode, GPU accelerated plotting library for [Dear ImGui](https://github.com/ocornut/imgui). It aims to provide a first-class API that ImGui fans will love. ImPlot is well suited for visualizing program data in real-time or creating interactive plots, and requires minimal code to integrate. Just like ImGui, it does not burden the end user with GUI state management, avoids STL containers and C++ headers, and has no external dependencies except for ImGui itself.  

<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/controls.gif" width="270"> <img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/dnd.gif" width="270"> <img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/pie.gif" width="270">

<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/query.gif" width="270"> <img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/bars.gif" width="270">
<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/rt.gif" width="270">

<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/stem.gif" width="270"> <img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/markers.gif" width="270">
<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/shaded.gif" width="270">

<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/candle.gif" width="270"> <img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/heat.gif" width="270">
<img src="https://raw.githubusercontent.com/wiki/epezent/implot/screenshots3/tables.gif" width="270">

## Features

- GPU accelerated rendering
- multiple plot types:
    - line plots
    - shaded plots
    - scatter plots
    - vertical/horizontal bars graphs
    - vertical/horizontal error bars
    - stem plots
    - pie charts
    - heatmap charts
    - and more likely to come
- mix/match multiple plot items on a single plot
- configurable axes ranges and scaling (linear/log)
- support for time formatted x-axes
- reversible and lockable axes
- support for up to three independent y-axes
- controls for zooming, panning, box selection, and auto-fitting data
- controls for creating persistent query ranges (see demo)
- remappable input controls
- several plot styling options: 10 marker types, adjustable marker sizes, line weights, outline colors, fill colors, etc.
- 10 built-in and user definable colormaps
- optional plot titles, axis labels, and grid labels
- optional legend with toggle buttons to quickly show/hide items
- default styling based on current ImGui theme, but most elements can be customized independently
- customizable data getters and data striding (just like ImGui:PlotLine)
- relatively good performance for high density plots
- support for single and double precision data
- and more! (see [Announcements](https://github.com/epezent/implot/issues/48))

## Usage

The API is used just like any other ImGui `BeginX`/`EndX` pair. First, start a new plot with `ImPlot::BeginPlot()`. Next, plot as many items as you want with the provided `PlotX` functions (e.g. `PlotLine()`, `PlotBars()`, `PlotErrorBars()`, etc). Finally, wrap things up with a call to `ImPlot::EndPlot()`. That's it!

```cpp
if (ImPlot::BeginPlot("My Plot")) {
    ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
    ImPlot::PlotBars("My Bar Plot", values, 10);
    ...
    ImPlot::EndPlot();
}
```

Consult `implot_demo.cpp` for a comprehensive example of ImPlot's features.

## Interactive Demo

An online version of the demo is hosted [here](https://traineq.org/implot_demo/src/implot_demo.html). You can view the plots and the source code that generated them. Note that this demo may not always be up to date and is not as performant as a desktop implementation, but it should give you a general taste of what's possible with ImPlot. Special thanks to [pthom](https://github.com/pthom) for creating and hosting this!

## Integration

1) Add `implot.h`, `implot_internal.h`, `implot.cpp`, `implot_items.cpp` and optionally `implot_demo.cpp` to your sources. Alternatively, you can get ImPlot using [vcpkg](https://github.com/microsoft/vcpkg/tree/master/ports/implot). 
2) Create and destroy an `ImPlotContext` wherever you do so for your `ImGuiContext`:

```cpp
ImGui::CreateContext();
ImPlot::CreateContext();
...
ImPlot::DestroyContext();
ImGui::DestroyContext();
```

Of course, this assumes you already have an ImGui-ready environment. If not, consider trying [mahi-gui](https://github.com/mahilab/mahi-gui), which bundles ImGui, ImPlot, and several other packages for you.

## Special Notes

- If you experience data truncation and/or visual glitches, it is **HIGHLY** recommended that you EITHER:
    1) Handle the `ImGuiBackendFlags_RendererHasVtxOffset` flag in your renderer when using 16-bit indices (the official OpenGL3 renderer supports this) and use an ImGui version with patch [imgui@f6120f8](https://github.com/ocornut/imgui/commit/f6120f8e16eefcdb37b63974e6915a3dd35414be), OR...
    2) Enable 32-bit indices by uncommenting `#define ImDrawIdx unsigned int` in your `imconfig.h` file.
- By default, no anti-aliasing is done on line plots for performance reasons. If you use 4x MSAA, then you likely won't even notice. However, you can enable software AA per-plot with the `ImPlotFlags_AntiAliased` flag, or globally with `ImPlot::GetStyle().AntiAliasedLines = true;`.

## FAQ

**Q: Why?**

A: ImGui is an incredibly powerful tool for rapid prototyping and development, but provides only limited mechanisms for data visualization. Two dimensional plots are ubiquitous and useful to almost any application. Being able to visualize your data in real-time will give you insight and better understanding of your application.

**Q: Is ImPlot the right plotting library for me?**

A: If you're looking to generate publication quality plots and/or export plots to a file, ImPlot is NOT the library for you. ImPlot is geared toward plotting application data at realtime speeds with as little user code as possible. ImPlot does its best to create pretty plots (indeed there are quite a few styling options available), but it will always favor function over form.

**Q: Is ImPlot suitable for plotting large datasets?**

A: Yes, within reason. You can plot tens to hundreds of thousands of points without issue, but don't expect millions to be a buttery smooth experience. However, you can downsample extremely large datasets by telling ImPlot to stride your data at larger intervals if needed. 

**Q: Can plot styles be modified?**

A: Yes. Plot colors, palettes, and various styling variables can be pushed/popped or modified permanently on startup. Three default styles are available, as well as an automatic style. 

**Q: Does ImPlot support logarithmic scaling or time formatting?**

A: Yep! Both logscale and timescale are supported.

**Q: Does ImPlot support multiple y-axes? x-axes?**

A: Yes. Up to three y-axes can be enabled. Multiple x-axes are not supported. 

**Q: Does ImPlot support [insert plot type]?**

A: Maybe. Check the demo, gallery, or [Announcements](https://github.com/epezent/implot/issues/48) to see if your desired plot type is shown. If not, consider submitting an issue or better yet, a PR!

**Q: Does ImPlot support 3D plots?**

A: No, and likely never will since ImGui only deals in 2D rendering.

**Q: My plot lines look like crap!**

A: See the note about anti-aliasing under **Special Notes** above.

**Q: Does ImPlot provide analytic tools?**

A: Not exactly, but it does give you the ability to query plot sub-ranges, with which you can process your data however you like.

**Q: Can plots be exported/saved to image?**

A: Not currently. Use your OS's screen capturing mechanisms if you need to capture a plot. ImPlot is not suitable for rendering publication quality plots; it is only intended to be used as a visualization tool. Post-process your data with MATLAB or matplotlib for these purposes.

**Q: Does ImPlot handle double precision data?**

A: Yes, ImPlot accepts both `float` and `double` for all of its plotting functions.

**Q: Can ImPlot be used with other languages/bindings?**

A: Yes, you can use the C binding, [cimplot](https://github.com/cimgui/cimplot) with most high level languages. [DearPyGui](https://github.com/hoffstadt/DearPyGui) provides a Python wrapper, among other things. A Rust binding, [implot-rs](https://github.com/4bb4/implot-rs), is currently in the works. An example using Emscripten can be found [here](https://github.com/pthom/implot_demo). 
