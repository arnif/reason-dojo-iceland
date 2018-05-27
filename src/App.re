type state = {data: array(Fetcher.data)};

type action =
  | LoadData(array(Fetcher.data));

let component = ReasonReact.reducerComponent("App");
let make = _children => {
  ...component,
  initialState: () => {data: [||]},
  reducer: (action, _state) =>
    switch (action) {
    | LoadData(data) => ReasonReact.Update({data: data})
    },
  didMount: self => {
    Fetcher.fetchPost(
      ~url="https://immense-river-25513.herokuapp.com/add-location",
      ~body="arnif",
    );
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=data => {
      Js.log(data);
      self.send(LoadData(data));
    });
  },
  render: ({state}) =>
    <ComposableMap
      projectionConfig=(
        ComposableMap.typeProjectionConfig(~scale=100, ~rotation=[|1, 1|])
      )
      width=980
      height=551
      style=(ComposableMap.typeStyle(~width="100%", ~height="auto"))>
      <ZoomableGroup center=[|0, 20|] disablePanning=true>
        <Geographies geography="../world-50m.json">
          ...(
               (geographies, projection) =>
                 geographies
                 |> Array.mapi((i, gg) =>
                      <Geography
                        key=(string_of_int(i))
                        projection
                        geography=gg
                        style=(
                          Geography.typeStyle2(
                            ~default=
                              Geography.styleNest(
                                ~fill="#ECEFF1",
                                ~stroke="#607D8B",
                                ~strokeWidth=0.75,
                                ~outline="none",
                              ),
                            ~hover=
                              Geography.styleNest(
                                ~fill="#607D8B",
                                ~stroke="#607D8B",
                                ~strokeWidth=0.75,
                                ~outline="none",
                              ),
                            ~pressed=
                              Geography.styleNest(
                                ~fill="#FF5722",
                                ~stroke="#607D8B",
                                ~strokeWidth=0.75,
                                ~outline="none",
                              ),
                          )
                        )
                      />
                    )
             )
        </Geographies>
        <Markers>
          ...(
               state.data
               |> Array.map(mark => {
                    let (long, lat) = mark |. Fetcher.location;
                    <Marker
                      marker=(Marker.typeMarker(~coordinates=(lat, long)))>
                      <circle cx="0" cy="0" r="2" />
                    </Marker>;
                  })
             )
        </Markers>
      </ZoomableGroup>
    </ComposableMap>,
};