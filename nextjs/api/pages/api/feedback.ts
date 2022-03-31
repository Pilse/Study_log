import { NextApiRequest, NextApiResponse } from "next";
import fs from "fs";
import path from "path";

type Data = {
  message: string;
  feedback?: {
    id: string;
    email: string;
    text: string;
  };
};

function handler(req: NextApiRequest, res: NextApiResponse<Data>) {
  const { body } = req;
  console.log(body);
  if (req.method === "POST") {
    if (
      "email" in body &&
      typeof body.email == "string" &&
      "feedback" in body &&
      typeof body.feedback == "string"
    ) {
      const newFeedback = {
        id: new Date().toISOString(),
        email: body.email,
        text: body.feedback,
      };

      const filePath = path.join(process.cwd(), "data", "feedback.json");
      const fileData = fs.readFileSync(filePath);
      const data = JSON.parse(fileData.toString());
      data.push(newFeedback);
      fs.writeFileSync(filePath, JSON.stringify(data));
      res.status(201).json({ message: "Success!", feedback: newFeedback });
    }
  } else {
    res.status(200).json({ message: "This works!" });
  }
}

export default handler;
