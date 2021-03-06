const express = require("express");
const app = express();
const dotenv = require("dotenv");
const mongoose = require("mongoose");
const authRoute = require("./routes/auth");


dotenv.config();
app.use(express.json()); // allow data is format json.



mongoose
  .connect(process.env.MONGO_URL, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(console.log("Backend Connected to MongoDB..."))
  .catch((err) => console.log(err));


app.use("/api/auth", authRoute);

app.listen(process.env.PORT, () => {
  console.log("Backend is running " + process.env.PORT);
});
